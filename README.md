Current repo contain the set of tests, adopted for execution in [saveourtool](https://saveourtool.com/) platform.
with [save-cli](https://github.com/saveourtool/save-cli) engine

### Local run

Just execute

    ./run_local.sh

It will do the following steps:

1) Extract the files from `executable` directory to the root of project.

2) Run `./setup.sh` -- it will install required libraries and create directories, which will be used later.

3) Execute `./save-0.3.9-linuxX64.kexe . --report-type json --result-output file`

#### Explanation

The repository contain `save.toml` file, which responsible for configuration of `SAVE`.

In current version, it configured in such way, that it will find all tests, that
matched `testNameRegex` pattern, i.e. containing `EASY|MEDIUM|HARD` in names,
and pass each test file to the `run_save-cli.sh` script (it will be automatically done by `save.kexe`).

Firstly, the `run_save-cli.sh` script will create `*.bc` files for each test via `clang -emit-llvm` in `bc_dir`
and pass plugin, called `libAnalyzer.so` to the `llvm opt`.

The `libAnalyzer.so`, provided in the `executable` directory of repository will create
`.sarif` report files for each test, after what all reports will be collected in `reports` directory.

The `save` will produce the report in `save-reports` directory in `json` format.

It will contain detailed information about matched warnings, where expected warnings were taken from `.sarif` reports,
created by `libAnalyzer.so` and actual warnings extracted directly from the test files, according pattern `expectedWarningsPattern`.

**Note:** all warnings should be provided in tests like a comments:

```kotlin
// ;warn:10:5: [ENUMS_SEPARATED] enum is incorrectly formatted: enums must end with semicolon{{.*}}
enum class EnumValueSnakeCaseTest {
}
```
