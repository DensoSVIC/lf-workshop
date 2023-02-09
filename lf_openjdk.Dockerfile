FROM openjdk:17-alpine

RUN set -ex && apk add --no-cache gcc musl-dev cmake make git libc6-compat
RUN git clone --recursive https://github.com/lf-lang/lingua-franca.git && \
cd lingua-franca && \
git pull && \
git submodule update --init --recursive

ENV PATH="$PATH:/lingua-franca/bin"
RUN echo $PATH 
RUN /lingua-franca/bin/build-lf-cli