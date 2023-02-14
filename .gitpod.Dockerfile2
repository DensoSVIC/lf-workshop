# You can find the new timestamped tags here: https://hub.docker.com/r/gitpod/workspace-base/tags
FROM openjdk:17-jdk-slim

RUN apt-get update && apt-get install -yq \
    git \
    git-lfs \
    gcc \
    cmake \
    musl-dev \
    make \
    sudo \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

RUN git clone --recursive https://github.com/lf-lang/lingua-franca.git && \
cd lingua-franca && \
git pull && \
git submodule update --init --recursive

# Create the gitpod user. UID must be 33333.
RUN useradd -l -u 33333 -G sudo -md /home/gitpod -s /bin/bash -p gitpod gitpod
USER gitpod

# Use ENTRYPOINT not CMD so that command-line arguments go through
CMD ["/lingua-franca/bin/build-lf-cli"]