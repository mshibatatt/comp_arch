FROM ubuntu:20.04

ENV SHELL /bin/bash
ENV DEBIAN_FRONTEND noninteractive

## C++のビルドなどに必要なものを入れる
RUN apt-get update && apt-get install -y \
    build-essential cmake git wget  && \
    # clean-up
    apt-get autoremove -y && \
    apt-get clean &&\
    rm -rf /var/lib/apt/lists/* && \
    rm -rf /usr/local/src/*

CMD ["/bin/bash"]