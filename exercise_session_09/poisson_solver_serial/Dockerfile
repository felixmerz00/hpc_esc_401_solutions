# syntax=docker/dockerfile:1

FROM ubuntu:latest
COPY . /docker-container-folder
RUN apt-get update && apt-get install -y g++ && apt-get install -y make
WORKDIR docker-container-folder/
CMD make all && ./main
