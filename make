#!/bin/sh
cd c
./make
cd ../cs
./make
cd ../java
./make
cd ..
cp c/fixe.so _build/libfixe.so
cp cs/ManagedFixe.dll _build/ManagedFixe.dll
cp cs/ManagedFixe.pdb _build/ManagedFixe.pdb
cp cs/ManagedFixe.deps.json _build/ManagedFixe.deps.json
cp java/fixe4j.jar _build/fixe4j.jar
