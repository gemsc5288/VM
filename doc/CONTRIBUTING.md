# Contributing

Gracias por tu interes en contribuir a este proyecto.

Este documento describe las normas para contribuir al desarrollo del proyecto.

---

# Flujo de trabajo

El repositorio usa un modelo de ramas inspirado en GitFlow.

Ramas principales:

```
release      -> versiones estables
develop      -> desarrollo principal
refactor/*   -> refactorizaciones grandes
feature/*    -> nuevas funcionalidades
hotfix/*     -> correcciones urgentes
```

Reglas importantes:

* No hacer commits directamente en `release`
* Las nuevas funcionalidades deben desarrollarse en `feature/*`
* Los cambios estructurales grandes deben ir en `refactor/*`
* Los arreglos criticos deben ir en `hotfix/*`

---

# Crear una nueva feature

```
git checkout develop
git checkout -b feature/nombre-feature
```

Realiza los cambios necesarios y luego abre un Pull Request hacia `develop`.

---

# Refactorizaciones

Para cambios grandes en la arquitectura del proyecto:

```
git checkout develop
git checkout -b refactor/nombre-refactor
```

Una vez terminado se fusiona de nuevo en `develop`.

---

# Hotfix

Para arreglar errores en una versión estable:

```
git checkout release
git checkout -b hotfix/nombre-fix
```

Despues del arreglo:

```
git checkout release
git merge hotfix/nombre-fix

git checkout develop
git merge hotfix/nombre-fix
```

---

# Compilación del proyecto

El proyecto usa **CMake**.

## Linux

Instalar dependencias:

```
sudo apt install build-essential cmake libssl-dev
```

Compilar:

```
mkdir build
cd build
cmake ..
cmake --build .
```

Ejecutar:

```
./vm
```

---

## Windows

Requisitos:

* compilador C++
* CMake
* OpenSSL

Compilar:

```
mkdir build
cd build
cmake ..
cmake --build .
```

---

# Modos de compilación

Debug:

```
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

Release:

```
cmake -DCMAKE_BUILD_TYPE=Release ..
```

---

# Estilo de commits

Se recomienda usar mensajes claros y descriptivos.

Formato sugerido:

```
tipo: descripción corta
```

Ejemplos:

```
feat: add bytecode loader
fix: resolve memory leak in VM stack
refactor: improve memory allocator
docs: update build instructions
```

Tipos comunes:

```
feat      nueva funcionalidad
fix       corrección de errores
refactor  cambios internos sin alterar funcionalidad
docs      documentación
build     cambios en compilación
test      cambios en tests
```

---

# Pull Requests

Antes de abrir un PR asegurate de:

* El proyecto compila correctamente
* No hay warnings nuevos
* El código sigue el estilo del proyecto
* La funcionalidad esta probada

---

# Normas de código

Recomendaciones generales:

* mantener funciones pequeñas y claras
* evitar dependencias innecesarias
* documentar código complejo
* evitar optimizaciones prematuras

---

# Tests y debugging

Se recomienda comprobar el código con herramientas de analisis de memoria:

```
valgrind --leak-check=full ./vm
```

El proyecto debe ejecutarse sin fugas de memoria.

---

# Versionado

El proyecto usa **Semantic Versioning**:

```
MAJOR.MINOR.PATCH
```

Ejemplo:

```
0.1.0
0.2.0
1.0.0
```

---

Gracias por contribuir.
