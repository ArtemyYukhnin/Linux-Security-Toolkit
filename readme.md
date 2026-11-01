Linux Security Toolkit is a command-line utility that displays system infromation, process information and file metadata.

## Features

### System Information
- Display system information: operating system name, kernel release, kernel version, machine architecture.

### Process Information
- Display process information: PID, PPID, name, state.

### File Security Checks
- Display file metadata: type, UID, GID, file permissions.


## Requirements
- C++20
- CMake(3.23)
- g++, clang++ or another C++ compiler
- Linux

## Build
```bash
cmake -S . -B build
cmake --build build
```
The executable is located in build/security-toolkit

## Usage

### System Information

Displays information about the operating system, kernel, hostname, and CPU.

```bash
./build/security-toolkit system
```

### Process Information

Displays information about running processes, including their PIDs, parent PIDs, names, and states.

```bash
./build/security-toolkit processes
```

### File Security Checks

Displays file metadata, including its type, permissions, owner UID, and group GID.

```bash
./build/security-toolkit check-file file
```

## Project Structure

```
EVMProj/
|-- MakeLists.txt
|-- readme.md
|-- include/
|   |-- system_info.h
|   |-- process_info.h
|   |-- file_security.h
|-- src/
|   |-- main.cpp
|   |-- system_info.cpp
|   |-- process_info.cpp
|   |-- file_security.cpp
|-- build/
```

## Future Improvements

- Network information collection
- System log analysis
- System call tracing using `ptrace`
- Improved error handling
- Testing and documentation improvements
