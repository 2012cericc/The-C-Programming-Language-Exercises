// Exercise on page 79

/*
############################################################################
new options for this exercise
    Modify getch and ungetch to never have more than one character of
    pushback.
############################################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>      // for strlen()

#define BUFSIZE 1

int getch(void);
void ungetch(int);

char buf = 0;           // buffer for getch and ungetch

int main(){
    char s[100];
    int i = 0;

    while((s[i++] = getch()) != '\n'){
        ;
    }
    s[i] = '\0';

    printf("RESULT: %s\n", s);  // char string[] will be prepended to the input

    return 0;
}

int getch(void){    // get a (possibly pushed back) character
    int c;

    if(buf == 0){
        c = getchar();
    }else{
        c = buf;
    }
    buf = 0;
    return c;
}

void ungetch(int c){    // push character back on input
    if(buf == 0){
        buf = c;    
    }else{
        printf("ungetch: too many characters\n");
    }
}