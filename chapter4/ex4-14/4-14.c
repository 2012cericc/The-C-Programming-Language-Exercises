// Exercise on page 91

/*
############################################################################
new options for this exercise
    "Define a macro swap(t,x,y) that interchanges two arguments of type t".
############################################################################
*/

#include <stdio.h>

#define swap(t,x,y) {\
    t temp = x; \
    x = y;      \
    y = temp;   \
}


int main(){

    int i = 1;
    int j = 2;

    printf("before: i=%d, j=%d\n", i, j);
    swap(int,i,j);
    printf("after : i=%d, j=%d\n", i, j);

    return 0;
}