#!/bin/bash

set -e 

if [ -z "$1" ]; then
  echo "Usage: $0 <pypi_token>"
  exit 1
fi

IMAGE=quay.io/pypa/manylinux_2_28_aarch64

docker run \
  -v $(pwd):/app \
  $IMAGE \
  /bin/bash ./app/build-manylinux.sh $1
