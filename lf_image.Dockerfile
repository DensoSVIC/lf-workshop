FROM alpine:latest
RUN set -ex && apk add --no-cache gcc musl-dev cmake make git gcompat

# Source: https://github.com/anapsix/docker-alpine-java
ENV GLIBC_REPO=https://github.com/sgerrand/alpine-pkg-glibc
ENV GLIBC_VERSION=2.35-r0

RUN set -ex && \
    apk --update add libstdc++ curl ca-certificates && \
    for pkg in glibc-${GLIBC_VERSION} glibc-bin-${GLIBC_VERSION}; \
        do curl -sSL ${GLIBC_REPO}/releases/download/${GLIBC_VERSION}/${pkg}.apk -o /tmp/${pkg}.apk; done && \
    apk add --allow-untrusted /tmp/*.apk && \
    rm -v /tmp/*.apk && \
    /usr/glibc-compat/sbin/ldconfig /lib /usr/glibc-compat/lib

RUN git clone --recursive https://github.com/lf-lang/lingua-franca.git && \
cd lingua-franca && \
git pull && \
git submodule update --init --recursive

#RUN /lingua-franca/bin/build-lf-cli