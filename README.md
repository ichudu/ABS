# Absolute 0.13.0.1

https://www.absify.me

What is Absolute all about?
Absolute is a community of designers and developers that value great designs and how they can be used to improve your life and enjoyment of producing something that is special for you.

Our goal is to allow you to produce excellent quality products that are designed by you using our online configurator. Certain designs have the choice of being recorded in the Absolute blockchain, allow independent verification that the design you made is unique to you.

----------------

## Absolute Technical Details

| Area | Absolute Setting |
| ------ | ------ |
| Block Time | 1.5 minutes |
| Block Reward | 30 ABS |
| PoW Algorithm | Lyra2REv2 |
| MN Collateral | 2500 ABS |
| Rewards split | Miners 20% and MasterNodes 80% |
| Maximum supply | 52.5 M - 20.35 M Block Rewards and 32.15 M PoV |
| Difficulty retargeting algo | Dark Gravity Wave v3 | 




For building please see INSTALL / proper files in the doc subfolder.

Masternode install scripts are supported on Ubuntu 18.04 and 20.04

Development Process
-------------------

The `master` branch is meant to be stable. Development is normally done in separate branches.
[Tags](https://github.com/absolute-community/absolute/tags) are created to indicate new official,
stable release versions of Absolute Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/qa) of the RPC interface, written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/qa) are installed) with: `qa/pull-tester/rpc-tests.py`

The Travis CI system makes sure that every pull request is built for Windows, Linux, and OS X, and that unit/sanity tests are run automatically.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

Translations
------------

Changes to translations as well as new translations can be submitted to
[Absolute Core's Transifex page](https://www.transifex.com/projects/p/absolute/).

Translations are periodically pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

**Important**: We do not accept translation changes as GitHub pull requests because the next
pull from Transifex would automatically overwrite them again.

