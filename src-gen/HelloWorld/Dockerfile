# For instructions, see: https://www.lf-lang.org/docs/handbook/containerized-execution
FROM alpine:latest AS builder
WORKDIR /lingua-franca/HelloWorld
RUN set -ex && apk add --no-cache gcc musl-dev cmake make
COPY . src-gen
RUN set -ex && \
mkdir bin && \
cmake -DLF_REACTION_GRAPH_BREADTH=1 -DLF_THREADED=1 -DNUMBER_OF_WORKERS=0 -DSCHEDULER=NP -DLOG_LEVEL=2 -S src-gen -B bin && \
cd bin && \
make all

FROM alpine:latest
WORKDIR /lingua-franca
RUN mkdir bin
COPY --from=builder /lingua-franca/HelloWorld/bin/HelloWorld ./bin/HelloWorld

# Use ENTRYPOINT not CMD so that command-line arguments go through
ENTRYPOINT ["./bin/HelloWorld"]
