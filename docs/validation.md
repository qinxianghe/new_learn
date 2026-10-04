# Validation record

Date: 2026-10-04. Cleanup baseline commit: `848be90634fe86b8435d9e2b980112e3b937cc9e`.

## Preservation and structure

- 13 retained blobs are unchanged at their current paths.
- 0 generated build/cache/executable entries are omitted from the current tree; the baseline history remains available.
- New documents and required configuration/path adaptations are recorded in the cleanup pull request. No existing source history is rewritten.
- Current filenames have no case-insensitive collisions. Markdown file links and generated-output ignore rules are checked before publication.

## Checks and limits

- Apple Clang 21 / C++17: all four selected CMake targets built and exited with code 0.
- `overloads_and_file_io` printed `i = 5` and `s = Hello, World!`.
- `layout_and_endianness` printed structure size/alignment/offset observations and `little` on this arm64 Mac.
- The other two programs currently have empty entry points; successful execution does not test all class methods.
- Legacy `MyString` uses MSVC `strcpy_s`; incomplete notes and Visual Studio project files are not verified portable build targets.

