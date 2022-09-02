#ifndef CPUSCHEDULERSIMULATOR_HASHMAP_H
#define CPUSCHEDULERSIMULATOR_HASHMAP_H

#include <corecrt.h>
#include <stdbool.h>

///a hashmap implementation using external chaining for collisions

typedef struct
{
    void* buffer;
    void* v_start;

    int k_empty_start; //indexed by key_size
    int v_empty_start; //indexed by val_size

    int cap;
    int size;
} pair_soa;

typedef struct
{
    bool (*equals)(const void*, const void*);
    int (*hash_val)(const void*);
    pair_soa* arrays;
    int size;
    int buffer_width;
    int key_size;
    int val_size;
} hashmap;

hashmap* init_hashmap(int, bool (*)(const void*, const void*), int(*)(const void*), int, int);
void set_hashmap(hashmap*, int, bool (*)(const void*, const void*), int(*)(const void*), int, int);

//if you want to store pointers, do: hashmap_add(hm, &key_ptr, &val_ptr)
void hashmap_add(hashmap*, void*, void*);
bool hashmap_contains_key(hashmap*, void*);
bool hashmap_delete(hashmap*, void*);
void* hashmap_get_val_of(hashmap*, void*);
bool hashmap_update(hashmap*, void*, void*);
void free_hashmap(hashmap*);
void hashmap_to_arr(hashmap*, void*buffer);
#endif

