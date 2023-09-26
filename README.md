Current repo contain the set of tests, adopted for execution in [saveourtool](https://saveourtool.com/) platform.

### Local run

1) Extract the files from `executable` directory to the root of project.

2) Run `./setup.sh` -- it will install required libraries and create directories, which will be used later.  

3) Execute ./save-0.3.9-linuxX64.kexe . --log all --report-type json --result-output file 

#### Explanation

The repository contain `save.toml` file, which responsible for configuration of `SAVE`.

In current version, it configured in such way, that it will find all tests, that
matched `testNameRegex` pattern, i.e. containing `EASY|MEDIUM|HARD` in names,
and pass each test file to the `run_save-cli.sh` script (it will be automatically done by `save.kexe`).

The `run_save-cli.sh` script will create `*.bc` files for each test via `clang -emit-llvm`
and pass plugin, called `libAnalyzer.so` to the `llvm opt`.

The `libAnalyzer.so`, provided in the `executable` directory of repository will create
`.sarif` report files for each test, after what it will be collected in `reports` directory.



For local execution, you need to run following commands **in the root of project**

    ./setup.sh
    ./save-0.3.9-linuxX64.kexe . --log all --report-type json --result-output file