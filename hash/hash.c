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