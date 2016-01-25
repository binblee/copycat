#include <stdio.h>
#include "hash.h"

#define HELLO_WORLD "Hello World!"
int main() {
    HT* ht = ht_init();
    ht_set(ht,HELLO_WORLD,1);
    int value = ht_get(ht,HELLO_WORLD);
    printf("%d\n",value);
    ht_destroy(ht);
    return 0;
}