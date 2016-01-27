#include <stdlib.h>
#include <string.h>
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
    memset(ht->array, 0, sizeof(int) * ht->array_length );
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
    if(ht->array[pos].key == NULL){
        ht->array[pos].key_length = strlen(key);
        int key_length = ht->array[pos].key_length;
        ht->array[pos].key = malloc(key_length+1);
        memcpy(ht->array[pos].key, key, key_length);
        ht->array[pos].key[key_length] = 0;
        ht->array[pos].value = value;
        ht->num ++;
    }
    return 0;
}
int ht_get(HT* ht, char *key){
    int pos = djb2(key) % ht->array_length;
    if( ht->array[pos].key != NULL ){
        int key_length = strlen(key);
        if( key_length == ht->array[pos].key_length ){
            // length of two keys equal
            if(strncmp(ht->array[pos].key, key, key_length) == 0){
                return ht->array[pos].value;
            }
        }
    }
    return -1;
}