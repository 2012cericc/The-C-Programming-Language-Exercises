// Exercise on page 79

/*
############################################################################
new options for this exercise
    revise calculator to use getline instead of getch and ungetch
############################################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>      // for atof()

#define MAXOP 100       // max size of operand or operator
#define MAXVAL 100      // max depth of val stack
#define NUMBER '0'      // signal that a number was found
#define BUFSIZE 100

void push(double);
double pop(void);
int getop(char []);

int getline_custom(int lim);   // NEW

int sp = 0;         // next free stack position
double val[MAXVAL]; // value stack
char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       //next free position in buf

// reverse polish calculator
int main(){
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0){
                    push(pop() / op2);
                }else{
                    printf("error: zero devisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

// push: push f onto value stack
void push(double f){
    if(sp < MAXVAL){
        val[sp++] = f;
    }else{
        printf("error: stack full, can't push %g\n", f);
    }
}

// pop: pop and return top value from stack
double pop(void){
    if(sp > 0){
        return val[--sp];
    }else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

// NEW: getop: get next operator or numeric operand after reading a line
int getop(char s[]){
    int i, c;

    if(buf[bufp] == '\0'){
        if(getline_custom(BUFSIZE) == 0){
            return EOF;
        }else{
            bufp = 0;
        }   
    }

    while((s[0] = c = buf[bufp++]) == ' ' || c == '\t'){
        ;
    }
    s[1] = '\0';
    if(!isdigit(c) && c != '.'){
        return c;
    }
    i = 0;
    if(isdigit(c)){  // collect integer part
        while(isdigit(s[++i] = c = buf[bufp++])){
            ;
        }
    }
    if(c == '.'){   //collect fraction part
        while(isdigit(s[++i] = c = buf[bufp++])){
            ;
        }
    }
    s[i] = '\0';
    bufp--;
    return NUMBER;
    
}

// NEW: reads in a whole line instead of char by char
int getline_custom(int lim){
    int i;
    int c;
    bufp = 0;   // reset buf pointer for the new line

    for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){
        buf[i] = c;
    }
    
    if(c == '\n'){
        buf[i] = c;
        ++i;
    }
    buf[i] = '\0';
    return i;
}
