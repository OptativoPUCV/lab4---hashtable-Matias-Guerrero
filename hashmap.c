#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, void * value)
{
    int posicion = hash(key, map->capacity);

    while(map->buckets[posicion] != NULL && map->buckets[posicion]->key != NULL && is_equal(map->buckets[posicion]->key, key) != 1)
    {
        posicion = (posicion + 1) % map->capacity;
    }

    if(map->buckets[posicion] == NULL || map->buckets[posicion]->key == NULL)
    {
        map->buckets[posicion] = createPair(key, value);
        map->size++;
        map->current = posicion;
    }
}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity)
{
    HashMap* mapa = (HashMap*) malloc(sizeof(HashMap));

    mapa->buckets = (Pair**) calloc(capacity, sizeof(Pair *));
    mapa->capacity = capacity;
    mapa->size = 0;
    mapa->current = -1;

    return mapa;
}

void eraseMap(HashMap * map,  char * key) {    


}

Pair * searchMap(HashMap * map,  char * key) {   


    return NULL;
}

Pair * firstMap(HashMap * map) {

    return NULL;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}