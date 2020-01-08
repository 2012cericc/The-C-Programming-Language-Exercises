// Exercise on page 79

/*
############################################################################
new options for this exercise
    "Write routine ungets(s) that will push back an entire string onto the
    input".

    Prompt was interpreted to mean when the ungets(char s[]) command is
    used, char s[] will be pushed onto the buf buffer.
############################################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>      // for strlen()

#define BUFSIZE 100

void ungets(char s[]);
int getch(void);
void ungetch(int);

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       //next free position in buf

int main(){
    char s[BUFSIZE];
    char string[] = "UNGETS";   // string to be ungets()'d
    int i = 0;

    ungets(string);

    while((s[i++] = getch()) != '\n'){
        ;
    }
    s[i] = '\0';

    printf("RESULT: %s\n", s);  // char string[] will be prepended to the input

    return 0;
}

// NEW: push back string onto input
void ungets(char s[]){
    int len = strlen(s);
    if(len > BUFSIZE){
        len = BUFSIZE;
    }
    // send letters to ungetch() in reverse order
    while(len > 0){
        ungetch(s[--len]);
    }
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