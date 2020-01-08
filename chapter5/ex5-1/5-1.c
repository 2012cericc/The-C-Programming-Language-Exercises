// Exercise on page 97

/*
############################################################################
new options for this exercise
    "As written, getint treats a + or - not followed by a digit as a valid
    representation of zero. Fix it to push such a character back on
    the input"
############################################################################
*/

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

int getint(int *pm);
int getch(void);
void ungetch(int);

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       //next free position in buf

int main(){
    int i = 0;
    printf("%d, ", getint(&i));
    printf("%d\n", i);

    return 0;
}

// getch version from the text
int getint(int *pm){   // get next integer from input into *pm
    int c, sign;
    int d;

    while(isspace(c = getch())){    // skip whitespace
        ;
    }
    if(!isdigit(c) && c!=EOF && c!='+' && c!='-'){
        ungetch(c); // not a number
        return 0;
    }
    sign = (c=='-') ? -1 : 1;
    if(c == '+' || c == '-'){
        d = c;                      // NEW: handle a sign followed by non-digit
        if(!isdigit(c=getch())){
            if(c != EOF){
                ungetch(c);
            }
            ungetch(d);
            return d;
        }
    }
    
    for(*pm=0; isdigit(c); c=getch()){
        *pm = 10 * *pm + (c - '0');
    }
    *pm *= sign;
    if(c != EOF){
        ungetch(c);
    }
    return c;
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