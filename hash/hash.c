#include <stdlib.h>
#include "hash.h"

unsigned int djb2(char *str){
    unsigned int hash = 5381;
    int c;
    while( (c = *str ++) != 0 ){
        hash = ((hash << 5) + hash ) + c;
    }
    return hash;
}

unsigned int sdbm(char *str){
    unsigned int hash = 0;
    int c;

    while( (c = *str ++) != 0 ){
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}

HT* ht_init(){
    HT* ht = malloc(sizeof(HT));
    ht->array_length = 512;
    ht->array = malloc( sizeof(int) * ht->array_length );
    ht->num = 0;
    return ht;
}

int ht_destroy(HT* ht){
    if(ht != 0){
        free(ht->array);
        ht->array_length = 0;
        ht->num = 0;
        free(ht);
    }
    return 0;
}
int ht_set(HT* ht, char *key, int value){
    unsigned int hash = djb2(key);
    unsigned int pos = hash % ht->array_length;
    ht->array[pos] = value;
    return 0;
}
int ht_get(HT* ht, char *key){
    return ht->array[djb2(key) % ht->array_length];
}