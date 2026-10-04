# C++ Review

C++17 review exercises covering function overloads, file input, object layout, copy/assignment, and stream operators.

```text
examples/             Four selected compilable review examples
include/              Counter declarations used by the layout example
notes/                Incomplete exercises and original memory-management notes
legacy/my_string/     Original custom string implementation and demonstration
legacy/visual-studio/ Historical Visual Studio project files
docs/                 File mapping and validation
```

## Build

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/overloads_and_file_io
./build/layout_and_endianness
```

`copy_and_assignment` and `stream_operators` compile class declarations and an empty demonstration entry point. Their current programs do not exercise all class behavior.

The custom `MyString` implementation is retained under `legacy/`: it uses MSVC-specific `strcpy_s` and is not included in the macOS CMake targets. Its behavior has not been comprehensively validated.

`notes/incomplete_new05.cpp` contains only `10`; `memory_management_notes.cpp` mixes unfinished examples and explanatory prose. These are source notes, not build targets. The old Visual Studio project needs path updates after relocation.

See [source mapping](docs/catalog.md) and [validation record](docs/validation.md). The original comments and code are preserved; comments may contain learning mistakes.
