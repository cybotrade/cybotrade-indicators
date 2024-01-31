#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <pypi_token>"
    exit 1
fi

ARCH=$(uname -m)

yum groupinstall -y "Development Tools" && \
  yum install -y wget && \
  wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-$ARCH.sh && \
  bash Miniconda3-latest-Linux-$ARCH.sh -b && \
  /root/miniconda3/bin/conda init && \
  source ~/.bashrc && \
  conda install python -y && \
  cd app && \
  make deps && \
  make release && \
  cd dist && \
  auditwheel repair $(find . -name cybotrade_indicators*.whl) && \
  TWINE_USERNAME=__token__ TWINE_PASSWORD=$1 python -m twine upload --repository pypi wheelhouse/*
