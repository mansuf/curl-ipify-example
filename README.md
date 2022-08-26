# curl-ipify-example

An example how to use [libcurl](https://curl.se/libcurl/) &amp; [nlohmann-json](https://github.com/nlohmann/json) for [ipify](https://www.ipify.org/)

## Prerequisites

- [CMake](https://cmake.org/) v3.2
- [nlohmann-json](https://github.com/nlohmann/json) library for parsing and dumping JSON data
- [libcurl](https://curl.se/libcurl/) library for HTTP(s) request

## Usage

```shell
# Clone the repository
git clone https://github.com/mansuf/curl-ipify-example.git
cd curl-ipify-example

# Build the app
cmake --build "./build"

# Run the app
cd "./build/Release"
curl_ipify.exe
```

## My tools during development 

- [CMake](https://cmake.org/) v3.2, build automation
- [vcpkg](https://github.com/microsoft/vcpkg), Package manager
- [vscode](https://github.com/microsoft/vscode), Code editor
- [Windows Terminal](https://github.com/microsoft/terminal), Command prompt / terminal
