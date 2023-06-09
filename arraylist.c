#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
    ArrayList *l = NULL;
    l = (ArrayList *) malloc(sizeof(ArrayList));
    if(l == NULL) exit(EXIT_FAILURE);
    l->data = (void *) calloc(2,sizeof(void));
    l->capacity = 2;
    l->size = 0;
    return l;
}

void append(ArrayList * l, void * data){
    if (l->size == l->capacity){
        l->capacity = l->capacity * 2;
        l->data = (void **)realloc (l->data, l->capacity*sizeof(void *));
    }
    l->data[l->size] = data;
    l->size++;
    return;
}

void push(ArrayList * l, void * data, int i){
    if(i > l->size) return;
  
    if (l->size == l->capacity){
        l->capacity *= 2;
        l->data = (void **) realloc (l->data, l->capacity*sizeof(void*));
    }
  
    for(int j = l->size; j > i; j--){
      l->data[j] = l->data[j-1];
    }
  
    l->data[i] = data;
    l->size++;
    return;
}

void* get(ArrayList * l, int i){
    if (i >= l->size) return NULL;
    if (i < 0) i = i+l->size;
    return l->data[i];
}

int get_size(ArrayList * l){
    return l->size;
}

void* pop(ArrayList * l, int i){
    if(i >= l->size || i < l->size * (-1) || l->size == 0) return NULL;
  
    if (i < 0) i = i+l->size;
  
    void* algo = NULL;
    algo = l->data[i];

    for(int j = i; j < l->size-1; j++){
      l->data[j] = l->data[j+1];
    }
    l->size--;
  
    return algo;
}

//remove elements
void clean(ArrayList * l){
  l->data = (void *) realloc(l->data,2*sizeof(void));
  l->capacity = 2;
  l->size = 0;
  return;
}
