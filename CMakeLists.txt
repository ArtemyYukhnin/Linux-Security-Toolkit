cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 20)

project(LinuxSecurityToolkit)

add_executable(security-toolkit)

target_sources(security-toolkit
  PRIVATE
  src/main.cpp
  src/system_info.cpp
  src/process_info.cpp
  src/file_security.cpp
)


target_compile_options(security-toolkit PRIVATE
  -Wall
  -Wextra
  -Wpedantic
 )
