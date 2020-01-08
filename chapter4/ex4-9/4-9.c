// Exercise on page 79

/*
############################################################################
new options for this exercise
    Have getch and ungetch handle a pushed-back EOF correctly.
############################################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>      // for atof()

#define BUFSIZE 100

int getch(void);
void ungetch(int);

int buf[BUFSIZE];   // NEW: changed from char to int array
int bufp = 0;       //next free position in buf

int main(){
    
    return 0;
}

int getch(void){    // get a (possibly pushed back) character
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){    // push character back on input
    if(bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
    }else{
        buf[bufp++] = c;
    }
}