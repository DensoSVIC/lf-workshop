# You can find the new timestamped tags here: https://hub.docker.com/r/gitpod/workspace-base/tags
FROM ubuntu:latest

RUN apt-get update && apt-get install -yq \
    sudo \
    openjdk-17-jdk \
    npm \
    lsb-core
RUN mkdir scripts
COPY .scripts .scripts

RUN bash ./.scripts/setup.bash nightly --no-example
ENV PATH="$PATH:/lingua-franca/bin"

# To install RTI at /usr/local/bin/RTI (Note the commit after which this failed)
#RUN git clone https://github.com/lf-lang/reactor-c.git && \
#cd reactor-c/core/federated/RTI/ && \
#git checkout f5d714c9 && \
#mkdir build && cd build && \
#cmake ../ && \
#make && \
#sudo make install

# Create the gitpod user. UID must be 33333.
RUN useradd -l -u 33333 -G sudo -md /home/gitpod -s /bin/bash -p gitpod gitpod
USER gitpod
