// Exercise on page 88

/*
############################################################################
new options for this exercise
    Write a recursive version of itoa which converts an integer into
    a string.
############################################################################
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

void itoa(int n, char s[]);
void printd(int n);

int main(){
    char s[MAXSIZE];

    itoa(1234, s);
    printf("string: %s\n", s);

    return 0;
}

// NEW: convert int to string
void itoa(int n, char s[]){
    static int i;

    if(n / 10){
        itoa(n/10, s);
    }else{
        i = 0;
        if(n < 0){
            s[i++] = '-';
        }
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}


// printd from text as reference
void printd(int n){
    if(n < 0){
        putchar('-');
        n = -n;
    }

    if(n / 10){
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}
