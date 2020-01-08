#include <stdio.h>
#include <ctype.h>      // for atof()
#include "calc.h"


// getop: get next operator or numeric operand
int getop(char s[]){
    int i, c;
    static int prevch = 0;  //  NEW: static variable

    if(prevch == 0){
        c = getch();
    }else{
        c = prevch;
        prevch = 0;
    }

    while((s[0] = c) == ' ' || c == '\t'){
        c = getch();
    }
    s[1] = '\0';
    if(!isdigit(c) && c != '.'){
        return c;
    }
    i = 0;
    if(isdigit(c)){  // collect integer part
        while(isdigit(s[++i] = c = getch())){
            ;
        }
    }
    if(c == '.'){   // collect fraction part
        while(isdigit(s[++i] = c = getch())){
            ;
        }
    }
    s[i] = '\0';

    if(c != EOF){
        prevch = c; // NEW: use prevch instead of ungetch()
    }
    return NUMBER;
}
