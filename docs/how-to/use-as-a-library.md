# Use the project as a library

Every module that is not `INTERNAL` installs as `QsReview38::<module>`. A consumer never gets tests, apps, or `-Werror`.

When you want the modules in another project, install the release build into a prefix:

```bash
make release && cmake --install build/release --prefix "$HOME/.local"
```

In the consumer's `CMakeLists.txt`:

```cmake
find_package(QsReview38 REQUIRED)
target_link_libraries(app PRIVATE QsReview38::core)
```

Configure the consumer with this project's compiler file and dependencies; `<qs_review_38>` is this checkout, `<triplet>` the directory under `vcpkg_installed/`:

```bash
cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=<qs_review_38>/cmake/toolchain/compiler.cmake -DCMAKE_PREFIX_PATH="$HOME/.local;<qs_review_38>/build/release/vcpkg_installed/<triplet>"
```

When the consumer builds the project from source instead, `FetchContent` or `add_subdirectory` works too:

```cmake
FetchContent_Declare(qs_review_38 GIT_REPOSITORY https://github.com/<owner>/qs_review_38.git GIT_TAG v0.1.0)
FetchContent_MakeAvailable(qs_review_38)
```

When you want a release archive, `build/release/package/QsReview38-<version>-<system>.tar.gz`:

```bash
cpack --config build/release/CPackConfig.cmake
```

The version lives only in `project(VERSION)`. `<qs_review_38/version.hpp>` gives `version_string`, `git_commit`, and `git_dirty`.
