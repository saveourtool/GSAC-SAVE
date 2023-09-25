#!/bin/bash

set -e

FILE_PATH=${1}

# were created in setup.sh
BITCODE_DIR="./bc_dir"
REPORT_DIR="./reports"

FILE_NAME_WITH_EXTENSION=${FILE_PATH##*/}
FILE_NAME=${FILE_NAME_WITH_EXTENSION%.*}

TEST_SUITE_PATH=$(dirname $(dirname "$FILE_PATH"))
TEST_SUITE_NAME=${TEST_SUITE_PATH##*/}

UNIQUE_NAME="${TEST_SUITE_NAME}_$FILE_NAME"

cd $BITCODE_DIR

clang-12 -g -O0 -c -emit-llvm ${FILE_PATH} -o "$UNIQUE_NAME.bc"

cd -

opt-12 -load-pass-plugin ./libAnalyzer.so -passes=simple -disable-output "$BITCODE_DIR/${UNIQUE_NAME}.bc"

REPORT="$UNIQUE_NAME.sarif"

cp "report.sarif" "$REPORT_DIR/$REPORT" || echo "failed to run on $FILE_NAME"