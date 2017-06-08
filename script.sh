#!/bin/bash

gcc tad-*.c -c
gcc leitura.c -o leitura tad-*.o
gcc main.c -o main tad-*.o

./leitura
