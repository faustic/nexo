# Nexo

*Copyright © Faustic Inferno SL*

*Licensed under the MIT License*

## How to modify

### Programming language

The programming language of the project is C++. For certain platforms, other languages can also be used where deemed necessary or convenient.

### Target platforms

We have commitment to no platforms. We target platforms according to circumstances. If we implement a certain feature for a platform, it does not mean that every Nexo feature will be implemented for that platform. It is not even guaranteed that a platform exists where every Nexo feature is implemented.

### Project organisation

Source files in the project consist of public headers, implementation files and private headers.

#### Public headers

Public headers are under directory `include/nexo` at the root of the project repository. They are platform-independent and organised by category. They are expected to be included from client programs with the syntax:

    #include <nexo/...>
    
Build options must be set accordingly concerning header search paths.

#### Implementation files

Implementation files are under directory `impl` at the root of the project repository. They are platform-dependent and are grouped by platform and category. How we group files by platform will be determined by our [concept of platform](platform/README.md). A directory `impl/common` contains some platform-independent implementation files, but it is likely that this directory will be removed in the future, and its contents reorganised differently.

Client programs typically use Nexo implementation files in one of three different ways, some of which may not be available in all platforms:

1. Add Nexo implementation files to the client program project and build them all together with the same compiler and linker. It is the best way to ensure that all modules use the same ABI.
2. Build Nexo as a static library and combine it at build-time with the client program. This usually achieves faster build time than option 1 and fewer potential conflicts than option 3.
3. Build Nexo as a shared library and combine it at load-time with the client program, either distributing the shared library along with the program or expecting the final user to have it installed. This option should result in the fastest build time and the smallest executable size.

#### Private headers

A private header is not intended to be included from client programs. It is usually in the same directory as a corresponding implementation file, and contains platform-dependent code and implementation details. Its declarations are generally needed by more than one implementation file, which is why they are headers rather than part of an implementation file.

#### Categories

Besides being organised by platform, source files are organised by category. Each category is represented by a subdirectory under `include/nexo` (category interface) and corresponding subdirectories under each supported platform under `impl` (category implementation).

Currently, only the following categories have been defined:

* `fs`: functions related to the file system. Not intended to deal with file data, but with platform-dependent features such as file system metadata (permissions, modification date, etc.).
* `gui`: functions related to the graphical user interface.
* `io`: functions related to communication with devices. Not intended for regular file input/output, although it may also be included if at some time we deem the standard library insufficient for this need.

Categories are organised hierarchically. A category can have subcategories, represented by subdirectories of the parent category. A category depends on its subcategories, but it does not depend on its parent nor sibling categories. In other words, a category interface directory with the corresponding category implementation directory should be usable as a smaller library independently from the rest of the library.
