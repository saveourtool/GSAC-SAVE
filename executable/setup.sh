#!/usr/bin/env bash

# ---------------------------------- install_required_packages -------------------------------- #

if [ "$EUID" -eq 0 ]
then
  apt-get update && apt-get install -y clang-12 cmake build-essential clang-format libclang-12-dev \
                                     python3 python3-clang-12 python3-pip curl gnupg gnupg2
fi

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
