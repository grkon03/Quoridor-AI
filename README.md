# Quoridor-AI

Quoridor AI and evaluation function.

## Edit

When you are to edit this repository, you **must** follow the following rules.

- Separate compilation
  - Prototype declarations should be written in .hpp files.
  - Implementation should be written in .cpp files.
  - **EXCEPTION**: Implementaions using `template` should be written in .hpp files.
- CMake
  - Follow the rules of CMake.
  - After you edit or make .cpp files, fix `CMakeLists.txt` respect to your edits.

## Build

Build with CMake.

### build QuoridorAI

Make `src/build` directory, and move there. In `Quoridor-AI` folder

```
cd src
mkdir build
cd build
```

Build with using cmake commands.

```
cmake ..
cmake --build .
```

### build test and run

Make `test/build` directory, and move there. In `Quoridor-AI` folder

```
cd test
mkdir build
cd build
```

Build with using cmake commands.

```
cmake ..
cmake --build .
```

Type the following binary file to run test.

```
./QuoridorAITest
```

### Design

The program design is written in HackMD in Japanese.

[Design - HackMD](https://hackmd.io/3Ro1CFVLSeSJtVc-KsqLow)
