#include <stdio.h>
#include "hash.h"

int main() {
    unsigned int hash = djb2("Hello World!");
    printf("dbj2 hash %u\n",hash);

    hash = sdbm("Hello World!");
    printf("sdbm hash %u\n", hash);
    return 0;
}