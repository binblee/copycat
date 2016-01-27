#include <stdlib.h>
#include <string.h>
#include "hash.h"

#include <stdio.h>

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
    ht->array = malloc( sizeof(HT_ITEM) * ht->array_length );
    memset(ht->array, 0, sizeof(HT_ITEM) * ht->array_length );
    ht->num = 0;
    return ht;
}

int ht_destroy(HT* ht){
    if(ht != 0){
        for( int i=0; i< ht->array_length; i++){
            if(ht->array[i].key != NULL){
                // TODO free list
                free(ht->array[i].key);
            }
        }
        free(ht->array);
        ht->array_length = 0;
        ht->num = 0;
        free(ht);
    }
    return 0;
}

int _ht_set_slot(HT* ht, int slot, char *key, int value){
    if(ht->array[slot].key == NULL){
        ht->array[slot].key_length = strlen(key);
        int key_length = ht->array[slot].key_length;
        ht->array[slot].key = malloc(key_length+1);
        memcpy(ht->array[slot].key, key, key_length);
        ht->array[slot].key[key_length] = 0;
        ht->array[slot].value = value;
        ht->num ++;
    }
    return 0;
}

int _ht_get_slot(HT* ht, int slot, char *key){
    if( ht->array[slot].key != NULL ){
        int key_length = strlen(key);
        if( key_length == ht->array[slot].key_length ){
            // length of two keys equal
            if(strncmp(ht->array[slot].key, key, key_length) == 0){
                return ht->array[slot].value;
            }
        }
    }
    return -1;
}

unsigned int _ht_slot(HT* ht, char* key){
    unsigned int slot = djb2(key) % ht->array_length;
    return slot;
}

int ht_set(HT* ht, char *key, int value){
    unsigned int slot = _ht_slot(ht, key);
    return _ht_set_slot(ht, slot, key, value);
}
int ht_get(HT* ht, char *key){
    unsigned int slot = _ht_slot(ht, key);
    return _ht_get_slot(ht, slot, key);
}