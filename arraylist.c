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
    ArrayList *lista = NULL;
    lista = (ArrayList *) malloc(sizeof(ArrayList));
    if(lista == NULL) exit(EXIT_FAILURE);
    lista->data = (void *) calloc(2,sizeof(void));
    lista->capacity = 2;
    lista->size = 0;
    return lista;
}

void append(ArrayList * l, void * data){
    if (l->size == l->capacity){
        l->capacity *= 2;
        l->data = (void *) realloc (l->data, l->capacity*sizeof(void));
    }
    l->data[l->size] = data;
    l->size++;
    return;
}

void push(ArrayList * l, void * data, int i){
    if(i > l->size) return;
    if (l->size == l->capacity){
        l->capacity *= 2;
        l->data = (void *) realloc (l->data, l->capacity*sizeof(void));
    }
    if(i != l->size){
      int j = i;
      for(; j < (l->size); j++){
        l->data[j+1] = l->data[j];
      }
    }
    l->data[i] = data;
    l->size++;

}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
