#!/usr/bin/bash

sudo cp -rp executable/* .

sudo ./setup.sh

./save-0.3.9-linuxX64.kexe . --log results_only
