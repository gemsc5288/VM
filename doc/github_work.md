# Forma de operar con Git


```
release      -> versiones estables
develop      -> desarrollo principal
refactor     -> cambios internos grandes
feature/*    -> nuevas features
hotfix/*     -> arreglos urgentes
```

-----

## release
- Solo versiones estables
- Siempre compilable
- usada para tags

Ejemplo:
```
v0.1
v0.2
v1.0
```
> Nunca desarrollar directamente aqui.
> Aqui se fusionan:
> nuevas features, refactors terminados.

## refactor
Para cambios grandes como:

- cambiar arquitectura
- reorganizar carpetas
- optimizar VM
- cambiar sistema de memoria

## feature/*

Para nuevas cosas:
```
feature/bytecode-loader
feature/crypto
feature/garbage-collector
feature/jit
```
Se crean desde develop y luego se fusionan de vuelta.

## hotfix/*
Para arreglos rapidos en producción.
```
hotfix/openssl-crash
hotfix/memory-leak
```

Se crean desde release:
```bash
git checkout release
git checkout -b hotfix/fix-crash
```
Tras arreglar:
```
git checkout release
git merge hotfix/fix-crash

git checkout develop
git merge hotfix/fix-crash
```

----

# Nueva feature

```bash
git checkout develop
git checkout -b feature/new-opcodes
```
Se hace los cambios oportunos y luego:
```bash
git checkout develop
git merge feature/new-opcodes
```

# Refactor grande

```bash
git checkout develop
git checkout -b refactor/memory-system
```
cuando termine:
```bash
git checkout develop
git merge refactor/memory-system
```

## develop

Rama principal de desarrollo.

Aqui se integran:
- nuevas features
- refactors terminados

Debe mantenerse funcional aunque no necesariamente estable.

# Crear release/*
Cuando develop este estable:

```bash
git checkout -b release
git merge develop
git tag v0.1
git push origin release --tags
```
creamos un GitFlow:
```
release/0.1
release/0.2
```

----

## Flujo completo

```
feature/* ----\
               \
refactor/* -----> develop -----> release -----> tag
               /
hotfix/* -----/
```

# Sistema de versionado

Se usa Semantic Versioning:
```
MAJOR.MINOR.PATCH
```

Ejemplo:
```bash
0.1.0  primera VM funcional
0.2.0  loader de bytecode
0.3.0  sistema crypto
1.0.0  VM estable
```

----