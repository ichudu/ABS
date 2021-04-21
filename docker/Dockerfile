FROM debian:stretch
LABEL maintainer="Absolute Developers <contact@absify.me>"
LABEL description="Dockerised AbsoluteCore, built from Travis"

RUN apt-get update && apt-get -y upgrade && apt-get clean && rm -fr /var/cache/apt/*

COPY bin/* /usr/bin/
