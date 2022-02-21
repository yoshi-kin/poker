FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

# wgetをインストール
RUN apt-get update && \
    apt-get install -y build-essential cmake clang libssl-dev vim wget
