# A1: String Map

## The Assignment

A map or dictionary data structure is a key-value data store. Although the underlying implementation can vary drastically, a map's API generally looks very similar to an array, although with strings as indexes as opposed to decimal numbers. 

This assignment will have you producing your own implementation of a map. You will be using this data structure throughout the course on various assignments, so it's very important that you take your time and render a working project. 

The underlying implementation is unimportant, so long as it is reasonable. Under normal circumstances, this would likely be implemented as a hash table (such as Java's HashMap<K,V> utility class). For the purpose of this class, however, it will be fine to implement it as some sort of linked list, so long as this detail is hidden by the API. 

For a review of linked lists (in terms of C), you may want to check out [Stanford Linked List Basics](http://cslibrary.stanford.edu/103/LinkedListBasics.pdf). 

## The Files

You are given two files - `map.h` and `map.c`.

`map.h` contains all of the required function prototypes as well as two skeleton structs. You may add members to these structs as you see fit, depending on how you choose to implement your map. The only requirement is that your top-level map type be called `map_t`. Here are the provided structs:

```c
typedef struct _map_entry map_entry_t;
struct _map_entry {
  char* key;
  char* value;
  map_entry_t* next;
};

typedef struct _map {
  map_entry_t* entry; 
  int size;
} map_t;
```

`map.c` contains empty function definitions for each of the functions required for the assignment. 

## The Protos

The map itself will be passed as the first parameter to each of its functions. This is a pattern that allows programmers to closely mimic object-oriented design patterns in C and is generally considered good practice for functions which operate on a particular data structure. 

### Part 1 (due on 1/16/14)

```c
void map_init(map_t* self);
```
Initialize the dictionary structure. May be empty if no initialization logic is required. 

```c
int map_put(map_t* self, const char* key, const char* val);
```
Add an entry to the map with the provided key and value. Returns OK on success, SYS_ERROR if an error occurred within a system call, and KEY_EXISTS if the key already exists. 

```c
const char* map_get(map_t* self, const char* key);
```
Returns the value of the entry associated with the given key. If no value exists for the given key, returns `NULL`.

```c
int map_remove(map_t* self, const char* key);
```
Removes the entry associated with the given key. Returns OK on success, SYS_ERROR if an error occurred within a system call, and NO_KEY_EXISTS if the key does not exist. 

```c
int map_size(map_t* self);
```
Returns the number of entries in the map. 

```c
void map_destroy(map_t* self);
```
Cleans up the dictionary structure. May be empty if no cleanup is required. 

Here is a usage example to demonstrate how the class should be used: 

```c
map_t* cool_map = malloc(sizeof *cool_map);

map_init(cool_map);

map_put(cool_map, "rofl", "copter");
map_put(cool_map, "copter", "rofl");

printf("%s\n", map_get(cool_map, "rofl"));
// => copter

map_remove(cool_map, "rofl");

printf("%s\n", map_get(cool_map, "rofl"));
// => NULL

map_destroy(cool_map);
```

### Part 2 (due on 1/21/14)

For part two, you will be required to implement serialization and deserialization functions for your data structure. These will read/write the keys and values stored in your dictionary in a super special proprietary format: 

    key1:value1
    key2:value2
    
Specifically, the key and value will be colon separated and each entry will be stored on a new line. 

You will also refactor your existing code to make use of the fancy new macros we created with the `#define` preprocessor directive. The prototype descriptions above have been modified accordingly. 

```c 
int map_serialize(map_t* self, FILE* stream);
```
Iterates through all key/value pairs in the map and outputs them to the supplied file stream in the above format. 

```c 
int map_deserialize(map_t* self, FILE* stream);
```
Reads key value pairs in the K:V format above from the provided file stream and adds them all to map object. 

## The Grade

Your assignment will be compiled and run through an automated test suite. For this reason, it is *IMPERATIVE* that you stick to the guidelines and naming conventions. If you do not, your code will not interact properly with the tests and you will be injustly rewarded with a bad grade. 
