#!/bin/bash

IMAGE_REPOSITORY=docker.pkg.github.com
IMAGE_NAME=kubernetes-client/c/crd-model-gen
IMAGE_VERSION=v1.0.0
IMAGE=${IMAGE_REPOSITORY}/${IMAGE_NAME}:${IMAGE_VERSION}

docker build . -t ${IMAGE} --network host --build-arg HTTP_PROXY=http://192.168.22.110:7071 --build-arg HTTPS_PROXY=http://192.168.22.110:7071

#docker push ${IMAGE}