#ifndef __HASH_H__
#define __HASH_H__

typedef struct _HT{
    int*   array;
    int     array_length;
    int     num;
} HT ;


HT* ht_init();
int ht_destroy(HT* ht);
int ht_set(HT* ht, char *key, int value);
int ht_get(HT* ht, char *key);

unsigned int djb2(char *str);
unsigned int sdbm(char *str);

#endif