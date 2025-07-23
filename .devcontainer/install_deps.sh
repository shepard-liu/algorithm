#!/usr/bin/env bash
echo "installing project dependencies"

# detect cpu architecture
CPU_ARCH=$(uname -m)
APT_SOURCE_FILE=""
case $CPU_ARCH in
x86_64)
    APT_SOURCE_FILE="apt-mirror-sources-x86_64.list"
    SMFMT_URL="https://github.com/mvdan/sh/releases/download/v3.6.0/shfmt_v3.6.0_linux_amd64"
    ;;
aarch64)
    APT_SOURCE_FILE="apt-mirror-sources-aarch64.list"
    SMFMT_URL="https://github.com/mvdan/sh/releases/download/v3.6.0/shfmt_v3.6.0_linux_arm64"
    ;;
*)
    echo "Unsupported CPU architecture: $CPU_ARCH"
    exit 1
    ;;
esac

# update apt sources
sudo cp ./$APT_SOURCE_FILE /etc/apt/sources.list
sudo apt update

# install dev dependencies
sudo apt install -y \
    libboost1.74-all-dev \
    libgtest-dev \

# install dev tools
sudo apt install -y \
    clang-15 \
    clangd-15 \
    clang-format-15 \
    lldb-15 \
    graphviz

# cmake formatter
pip install cmakelang

# shell formatter
wget -O /usr/local/bin/shfmt $SMFMT_URL
chmod +x /usr/local/bin/shfmt
