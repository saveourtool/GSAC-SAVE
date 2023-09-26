#!/usr/bin/env bash

sudo cp -rp executable/* .

sudo ./setup.sh

./save-0.3.9-linuxX64.kexe . --report-type json --result-output file
