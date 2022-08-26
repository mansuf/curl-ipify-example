# curl-ipify-example

An example how to use [libcurl](https://curl.se/libcurl/) &amp; [nlohmann-json](https://github.com/nlohmann/json) for [ipify](https://www.ipify.org/)

## Prerequisites

- [CMake](https://cmake.org/) v3.2
- [vcpkg](https://github.com/microsoft/vcpkg) for cpp package manager
- [nlohmann-json](https://github.com/nlohmann/json) library for parsing and dumping JSON data
- [libcurl](https://curl.se/libcurl/) library for HTTP(s) request

## Usage

```shell
# Clone the repository
git clone https://github.com/mansuf/curl-ipify-example.git
cd curl-ipify-example

# Build the app
# Replace {PATH_TO_vcpkg} to your vcpkg cmake script
# Example: vcpkg root directory is stored in /etc/vcpkg, so the {PATH_TO_vcpkg}
# would be /etc/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake -DCMAKE_TOOLCHAIN_FILE:STRING={PATH_TO_vcpkg.cmake} -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -S. -B./build
cmake --build "./build"

# Run the app
cd "./build/Release"
curl_ipify.exe
```
