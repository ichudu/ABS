#!/bin/sh

VERSION="absolutecore-0.12.2.5"
echo 'downloading last release'\
&& wget https://github.com/absolute-community/absolute/releases/download/v12.2.5/absolutecore-0.12.2.5-x86_64-linux-gnu.tar.gz -O absolute_latest.tar.gz \
&& echo "Extracting" \
&& tar -zxvf absolute_latest.tar.gz \
&& echo "Backuping"\
&& mv "$HOME/Absolute/absolute-cli" "$HOME/Absolute/absolute-cli.bkp" \
&& mv "$HOME/Absolute/absoluted" "$HOME/Absolute/absoluted.bkp" \
&& echo "updating" \
&& mv "$VERSION/bin/absolute-cli" "$HOME/Absolute/absolute-cli" \
&& mv "$VERSION/bin/absoluted" "$HOME/Absolute/absoluted" \
&& ln -sf $HOME/Absolute/absolute-cli /usr/local/bin/absolute-cli\
&& ln -sf $HOME/Absolute/absoluted /usr/local/bin/absoluted\
&& echo "done"

