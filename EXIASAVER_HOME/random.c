#include <stdio.h>
#include <stdlib.h>

int alea(int min, int max)
{
    int nbgen = 0;
    srand(time(NULL));
    nbgen=(rand() % (max - min +1)) + min;
    return nbgen;
}

