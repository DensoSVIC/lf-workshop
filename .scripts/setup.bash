#!/bin/bash

# This script sets up the lingua franca environment; right now, it only works on Ubuntu.
# it will use the nightly build of lingua franca, unless the second argument
# is "stable" where it will use the stable build, or "dev" where it will pull from the master branch and build it.

set -euxo pipefail

# Check if running Ubuntu; the whole script requires apt + an Ubuntu distro name (for cmake) to properly run.
DISTRIB_ID=$(lsb_release -is)
if [ -z "$DISTRIB_ID" || "$DISTRIB_ID" != "Ubuntu" ]; then
    echo "This script can only run on Ubuntu, but got distribution ID ${DISTRIB_ID}." 1>&2;
    exit 1
fi

# Install dependencies
sudo apt update
## Setup C, C++
sudo apt install --assume-yes build-essential
# Install latest CMake; see https://apt.kitware.com
DISTRIB_CODENAME=$(lsb_release -cs)
if [ -n "$DISTRIB_CODENAME" ]; then
    sudo apt install --assume-yes gpg wget
    wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | sudo tee /usr/share/keyrings/kitware-archive-keyring.gpg >/dev/null
    echo "deb [signed-by=/usr/share/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu/ ${DISTRIB_CODENAME} main" | sudo tee /etc/apt/sources.list.d/kitware.list >/dev/null
    sudo apt update && sudo apt install --assume-yes cmake
fi
## Setup Python
sudo apt install --assume-yes python3 python3-dev python3-pip
python3 -m pip install --exists-action i setuptools requests
pip3 install LinguaFrancaBase
python3 -m pip install pylint --upgrade
## Setup Typescript
npm install -g typescript
## Setup Rust
sudo apt install --assume-yes rustc

RELEASE_BUILD="nightly"
EXAMPLE=1

for arg in "$@"; do
    shift
    case "$arg" in
        'dev') RELEASE_BUILD="dev";;
        'stable') RELEASE_BUILD="stable";;
        '--no-example') EXAMPLE=0
    esac
done

# Use case here for maximum flexibility if we were to change later
case "$RELEASE_BUILD" in
    'dev') 
        git clone https://github.com/lf-lang/lingua-franca.git --branch master --depth 1
        cd lingua-franca
        git submodule update --init --recursive
        ./gradlew buildAll

        cd org.lflang/src/lib/c/reactor-c/core/federated/RTI && \
        mkdir build && cd build && \
        cmake ../ && \
        make && \
        sudo make install
        cd ..
    ;;
    *) 
        pip install requests
        ./.scripts/get-lf-executable $RELEASE_BUILD
        mkdir lingua-franca
        # While what we have here is tar.gz, lf release bot appear to have a bug and did not gunzip it.
        # Therefore `tar -xzf` will fail but `tar -xf` will work.
        # Here, we ignore the actual build name (the original name of the file and the original first directory). 
        tar -xf lf.tar.gz -C lingua-franca --strip-components 1
        rm lf.tar.gz
    ;;
esac

if [ $EXAMPLE ]; then
    git clone https://github.com/lf-lang/examples-lingua-franca.git examples --branch main
fi
