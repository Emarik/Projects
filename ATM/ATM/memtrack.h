#ifndef MEMORYTRACK_H
#define MEMORYTRACK_H

#include <stdlib.h>
#include <stdio.h>

#pragma comment(linker, "/nodefaultlib:libc.lib")
#pragma comment(linker, "/nodefaultlib:libcd.lib")

void* operator new(size_t s);

void operator delete(void* mem);

void* operator new[](size_t s);

void operator delete[](void* mem);

void print_memory();

#endif