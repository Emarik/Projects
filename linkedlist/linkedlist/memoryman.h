#ifndef MEMORYTRACK_H
#define MEMORYTRACK_H

#include <stdlib.h>
#include <stdio.h>

#pragma comment(linker, "/nodefaultlib:libc.lib")
#pragma comment(linker, "/nodefaultlib:libcd.lib")

#define MEM_WORK_STR_LEN 255
#define MEM_WORK_STR_LEN_N (MEM_WORK_STR_LEN + 1)

struct mem_struct_entry_s
{
	void * mem_addr;
	size_t memsize;
	struct mem_struct_entry_s* next;
};
typedef struct mem_struct_entry_s mem_struct_entry;

mem_struct_entry *memmap_head = NULL;

int ___new_size = 0;
int ___new_arr_size = 0;

void ____add_memory_node(void* memory, size_t size)
{
	mem_struct_entry* entry = NULL;
	entry = (mem_struct_entry*)malloc(sizeof(mem_struct_entry));
	entry->mem_addr = memory;
	entry->memsize = size;
	entry->next = NULL;

	if (memmap_head == NULL)
	{
		memmap_head = entry;
	}
	else
	{
		mem_struct_entry* current = memmap_head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = entry;
	}
}

size_t ____pop_memory_node(void* memory)
{
	size_t ret_size = 0;
	mem_struct_entry* current = memmap_head;
	if (memmap_head->mem_addr == memory)
	{
		ret_size = memmap_head->memsize;
		current = memmap_head;
		memmap_head = memmap_head->next;
		free(current);
	}
	else
	{
		current = memmap_head;
		while (current->next != NULL)
		{
			if (current->next->mem_addr == memory)
			{
				ret_size = current->next->memsize;
				mem_struct_entry* to_del = current->next;
				current->next = current->next->next;
				free(to_del);
				break;
			}
			current = current->next;
		}
	}
	return ret_size;
}

void* operator new(size_t s)
{
	void* mem = malloc(s);
	___new_size += s;
	____add_memory_node(mem, s);
	return mem;
}

void operator delete(void* mem)
{
	int s = ____pop_memory_node(mem);
	free(mem);
	___new_size -= s;
}

void* operator new[](size_t s)
{
	void* mem = malloc(s);
	___new_arr_size += s;
	____add_memory_node(mem, s);
	return mem;
}

void operator delete[](void* mem)
{
	int s = ____pop_memory_node(mem);
	free(mem);
	___new_arr_size -= s;
}

void print_memory()
{
	printf("memory bytes leaked: %d\n", ___new_size);
	printf("array memory bytes leaked: %d\n", ___new_arr_size);
}

#endif