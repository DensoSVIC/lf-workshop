# You can find the new timestamped tags here: https://hub.docker.com/r/gitpod/workspace-base/tags
FROM ubuntu:latest

RUN apt-get update && apt-get install -yq \
    sudo \
    openjdk-17-jdk \
    npm \
    lsb-core
RUN mkdir .scripts
COPY ../../.scripts .scripts

RUN bash ./.scripts/setup.bash nightly
ENV PATH="$PATH:/lingua-franca/bin"

# To install RTI at /usr/local/bin/RTI
RUN git clone https://github.com/lf-lang/reactor-c.git && \
cd reactor-c/core/federated/RTI/ && \
mkdir build && cd build && \
cmake ../ && \
make && \
sudo make install
