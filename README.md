# VM

----

clonar usando:
```bash
git clone  --recursive https://github.com/desmonHak/VM.git
```

## Instalacion en linux:

```bash
sudo apt install build-essential cmake libssl-dev
```

### Arch linux

```bash
sudo pacman -S openssl
```

## Compilacion en linux:

```bash
mkdir build
cd build
cmake -Wno-dev ..
cmake --build .
```

En caso de un error similar a este en linux:
```
Enabling CAPSTONE_ARC_SUPPORT
: not foundskF/C/VM/libs/SourceCode/keystone/llvm/cmake/config.guess: 6:
: not foundskF/C/VM/libs/SourceCode/keystone/llvm/cmake/config.guess: 8:
: not foundskF/C/VM/libs/SourceCode/keystone/llvm/cmake/config.guess: 28:
: not foundskF/C/VM/libs/SourceCode/keystone/llvm/cmake/config.guess: 29:
: not foundskF/C/VM/libs/SourceCode/keystone/llvm/cmake/config.guess: 40:
: not foundskF/C/VM/libs/SourceCode/keystone/llvm/cmake/config.guess: 42:
: not foundskF/C/VM/libs/SourceCode/keystone/llvm/cmake/config.guess: 54:
: not foundskF/C/VM/libs/SourceCode/keystone/llvm/cmake/config.guess: 65:
: not foundskF/C/VM/libs/SourceCode/keystone/llvm/cmake/config.guess: 68:
/root/WinDiskF/C/VM/libs/SourceCode/keystone/llvm/cmake/config.guess: 71: Syntax error: word unexpected (expecting "in")
CMake Error at libs/SourceCode/keystone/llvm/cmake/modules/GetHostTriple.cmake:24 (message):
  Failed to execute
  /root/WinDiskF/C/VM/libs/SourceCode/keystone/llvm/cmake/config.guess
Call Stack (most recent call first):
  libs/SourceCode/keystone/llvm/cmake/config-ix.cmake:293 (get_host_triple)
  libs/SourceCode/keystone/llvm/CMakeLists.txt:325 (include)
```

puede necesitar convertir los CRLF de Windows en LF de linux usando el siguiente comandos:
```bash
find ../libs/SourceCode -type f -exec dos2unix {} \;
```
generalmente esto permite que el proyecto se compile correctamente si ocurre el anterior error.


### Elegir modo 'Debug' o 'Release'

debug:
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

release:
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

Valgrind/profiling:
```bash
cmake -B build -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build build
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./vm```
```
----

## Forma de trabajo
Siga lellendo en: [github_work.md](./doc/github_work.md)

----