# You can find the new timestamped tags here: https://hub.docker.com/r/gitpod/workspace-base/tags
FROM ubuntu:latest

RUN apt-get update && apt-get install -yq \
    sudo \
    openjdk-17-jdk \
    npm \
    lsb-core
RUN mkdir scripts
COPY .scripts .scripts

RUN bash ./.scripts/setup.bash nightly
ENV PATH="$PATH:/lingua-franca/bin"

# Create the gitpod user. UID must be 33333.
RUN useradd -l -u 33333 -G sudo -md /home/gitpod -s /bin/bash -p gitpod gitpod
USER gitpod
