cmake_minimum_required(VERSION 3.2)
project(curl_ipify CXX)

find_package(CURL CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 11)

add_executable(curl_ipify main.cpp)

target_link_libraries(curl_ipify PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(curl_ipify PRIVATE CURL::libcurl)