// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparamsbase.h"

#include "tinyformat.h"
#include "util.h"

#include <assert.h>

const std::string CBaseChainParams::MAIN = "main";
const std::string CBaseChainParams::TESTNET = "test";
const std::string CBaseChainParams::POVNET = "pov";
const std::string CBaseChainParams::REGTEST = "regtest";

void AppendParamsHelpMessages(std::string& strUsage, bool debugHelp)
{
    strUsage += HelpMessageGroup(_("Chain selection options:"));
    strUsage += HelpMessageOpt("-testnet", _("Use the test chain"));
    if (debugHelp) {
        strUsage += HelpMessageOpt("-regtest", "Enter regression test mode, which uses a special chain in which blocks can be solved instantly. "
                                   "This is intended for regression testing tools and app development.");
    }
}

/**
 * Main network
 */
class CBaseMainParams : public CBaseChainParams
{
public:
    CBaseMainParams()
    {
        nRPCPort = 18889;
    }
};
static CBaseMainParams mainParams;

/**
 * Testnet (v3)
 */
class CBaseTestNetParams : public CBaseChainParams
{
public:
    CBaseTestNetParams()
    {
        nRPCPort = 17778;
        strDataDir = "testnet3";
    }
};
static CBaseTestNetParams testNetParams;

/**
 * PoVNET
 */
class CBasePoVNETParams : public CBaseChainParams
{
public:
    CBasePoVNETParams(const std::string &dataDir)
    {
        nRPCPort = 18890;
        strDataDir = dataDir;
    }
};
static CBasePoVNETParams *PoVNETParams;
/*
 * Regression test
 */
class CBaseRegTestParams : public CBaseChainParams
{
public:
    CBaseRegTestParams()
    {
        nRPCPort = 16667;
        strDataDir = "regtest";
    }
};
static CBaseRegTestParams regTestParams;

static CBaseChainParams* pCurrentBaseParams = 0;

const CBaseChainParams& BaseParams()
{
    assert(pCurrentBaseParams);
    return *pCurrentBaseParams;
}

CBaseChainParams& BaseParams(const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN)
        return mainParams;
    else if (chain == CBaseChainParams::TESTNET)
        return testNetParams;
    else if (chain == CBaseChainParams::POVNET) {
        assert(PoVNETParams);
        return *PoVNETParams;
    } else if (chain == CBaseChainParams::REGTEST)
        return regTestParams;
    else
        throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectBaseParams(const std::string& chain)
{
    if (chain == CBaseChainParams::POVNET) {
        std::string PoVNETName = GetPoVNETName();
        assert(!PoVNETName.empty());
        PoVNETParams = new CBasePoVNETParams(PoVNETName);
    }
    pCurrentBaseParams = &BaseParams(chain);
}

std::string ChainNameFromCommandLine()
{
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fPoVNET = mapArgs.count("-povnet") != 0;
    bool fTestNet = GetBoolArg("-testnet", false);

    int nameParamsCount = (fRegTest ? 1 : 0) + (fPoVNET ? 1 : 0) + (fTestNet ? 1 : 0);
    if (nameParamsCount > 1)
        throw std::runtime_error("Only one of -regtest, -testnet or -povnet can be used.");

    if (fPoVNET)
        return CBaseChainParams::POVNET;
    if (fRegTest)
        return CBaseChainParams::REGTEST;
    if (fTestNet)
        return CBaseChainParams::TESTNET;
    return CBaseChainParams::MAIN;
}

std::string GetPoVNETName()
{
    // This function should never be called for non-povnets
    assert(mapArgs.count("-povnet"));
    std::string PoVNETName = GetArg("-dpovnet", "");
    return "povnet" + (PoVNETName.empty() ? "" : "-" + PoVNETName);
}

bool AreBaseParamsConfigured()
{
    return pCurrentBaseParams != NULL;
}
