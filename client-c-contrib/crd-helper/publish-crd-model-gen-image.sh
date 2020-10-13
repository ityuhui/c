#!/bin/bash

IMAGE_REPOSITORY=docker.pkg.github.com
IMAGE_NAME=kubernetes-client/c/crd-model-gen
IMAGE_VERSION=v1.0.0
IMAGE=${IMAGE_REPOSITORY}/${IMAGE_NAME}:${IMAGE_VERSION}

docker build -t ${IMAGE} .

docker push ${IMAGE}