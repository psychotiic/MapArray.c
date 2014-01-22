#include <assert.h>
#include<stdlib.h>
#include "map.h"
#include <string.h>
int main(){
map_t* newList = malloc(sizeof(map_t));
map_init(newList);
const char* passString ="a";
const char* secondString="2";
map_put(newList,"3","3");
map_put(newList,"7","34");
map_put(newList,"a","45");
map_put(newList,passString,secondString);
map_get(newList,secondString);
}

void map_init(map_t* self) {
map_entry_t* newNode= malloc(sizeof(map_entry_t)); // allocate
self->size = 0;
self->entry = newNode; // link next
}

int map_put(map_t* self, const char* key, const char* val) {
  assert(self != NULL);
map_entry_t* current;
//current = self->entry->key;
while(current->next != NULL){
	current = current->next;
	
}
self->entry->key = key;
self->entry->value = val;
map_entry_t* newNode = malloc(sizeof(map_entry_t));


printf("\ntry printing the list \n");
printf(self->entry->key);
printf(" :was the key and the value is \n");
printf(self->entry->value);
printf("\n");


}

const char* map_get(map_t* self, const char* key) {
  assert(self != NULL);
const char* target = key;
int i=0;
for(i; i<=self->size; i++) 
{
printf("\n\ninside the list\n");
printf(self->entry->value);
printf("\n");
}
}

int map_size(map_t* self) {
  assert(self != NULL);
  
}

int map_remove(map_t* self, const char* key) {
  assert(self != NULL);
  
}

int map_serialize(map_t* self, FILE* stream) {
  assert(self != NULL);
  
}

int map_deserialize(map_t* self, FILE* stream) {
  assert(self != NULL);
  
}

void map_destroy(map_t* self) {
  assert(self != NULL);
  
}
 










