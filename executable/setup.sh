#!/usr/bin/env bash

# ---------------------------------- install_required_packages -------------------------------- #

if [[ "$EUID" -ne 0 ]]
then
  echo "Please run with root permission!" && exit 1
fi

apt-get update && apt-get install -y clang-12 cmake build-essential clang-format libclang-12-dev \
                                     python3 python3-clang-12 python3-pip curl gnupg gnupg2
pip3 install --prefix=/usr/local libclang==14.0.1 pysarif

PODMAM_SUB_REPO="/kubic:/libcontainers:/stable/xUbuntu_20.04/"
PODMAN_REPO="https://download.opensuse.org/repositories/devel:$PODMAM_SUB_REPO"

echo "deb $PODMAN_REPO /" | tee /etc/apt/sources.list.d/devel:kubic:libcontainers:stable.list
curl -L "$PODMAN_REPO/Release.key" | apt-key add -
apt-get update && apt-get install -y podman

# ---------------------------------------- build -------------------------------------------- #
create_directory() {
  DIRECTORY="$1"
  if [ -d "$DIRECTORY" ]; then
    rm -rf "$DIRECTORY"
  fi
  mkdir -p "$DIRECTORY"

}

BITCODE_DIR="./bc_dir"
create_directory "$BITCODE_DIR"

REPORT_DIR="./reports"
create_directory "$REPORT_DIR"