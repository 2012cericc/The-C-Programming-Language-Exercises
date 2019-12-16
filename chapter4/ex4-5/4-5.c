// Exercise on page 79
// needs to be compiled as "gcc 4-5.c -lm -o 4-5"

/*
############################################################################
part of exercise 4-4
    -print top element without popping  ('?' peek)
    -clear the stack                    ('c' clear)
    -duplicate top elements             ('d' dup)
    -swap top two elements              ('s' swap)

new options for this exercise
uses math.h
    -double sin(double)
    -double exp(double)
    -double pow(double x, double y)
############################################################################
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // for atof()
#include <string.h>
#include <math.h>

#define MAXOP 100   // max size of operand or operator
#define MAXVAL 100  // max depth of val stack
#define BUFSIZE 100
#define NUMBER '0'  // signal that a number was found
#define NAME 'n'    // signal that a name was found

void push(double);
double pop(void);
void name_ops(char []);
int getop(char []);
int getch(void);
void ungetch(int);

int sp = 0;         // next free stack position
double val[MAXVAL]; // value stack
char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       //next free position in buf

// reverse polish calculator
int main(){
    int type;
    double op1;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER:
                push(atof(s));
                break;
            case NAME:  // new for this exercise
                name_ops(s);
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
            case '%':
                op2 = pop();
                if(op2 != 0.0){
                    push(fmod(pop(), op2));
                }else{
                    printf("error: zero devisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case '?':   // peek top element
                op2 = pop();
                printf("\t%.8g\n", op2);
                push(op2);
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

// name_ops: perform a named operator
void name_ops(char s[]){
    double op1;
    double op2;

    if(strcmp(s, "c") == 0){
        sp = 0;
    }else if(strcmp(s, "d") == 0){
        op2 = pop();
        push(op2);
        push(op2);
    }else if(strcmp(s, "s") == 0){
        op1 = pop();
        op2 = pop();
        push(op1);
        push(op2);
    }else if(strcmp(s, "sin") == 0){
        push(sin(pop()));
    }else if(strcmp(s, "exp") == 0){
        push(exp(pop()));
    }else if(strcmp(s, "pow") == 0){
        op2 = pop();
        push(pow(pop(), op2));
    }else{
        printf("error: not a valid operator\n");
    }
}

// getop: get next operator or numeric operand
int getop(char s[]){
    int i = 0;
    int c;

    while((s[0] = c = getch()) == ' ' || c == '\t'){
        ;
    }
    s[1] = '\0';

    if(!isdigit(c) && c != '.' && c != '-'){    // non-numeric operator
        /*
        ############################################################################
        new for this exercise
            non-numeric related operator, could be the name of a function.
            if c is alphabetical, read all the letters into s[].
        ############################################################################
        */
        if(isalpha(c)){
            s[i++] = tolower(c);
            while(isalpha(c = getch())){
                s[i++] = tolower(c);
            }
            if(c == '\n' || c != EOF){
                ungetch(c);
            }
            s[i] = '\0';
            return NAME;
        }else{
            return c;   // operator is a symbol
        }      
    }

    if(c == '-'){   // handle negative numbers
        if(isdigit(c = getch()) || c == '.'){
            s[++i] = c;
        }else{
            if(c != EOF){
                ungetch(c);  
            }
            return '-';
        }
    }

    if(isdigit(c)){  // collect integer part
        while(isdigit(s[++i] = c = getch())){
            ;
        }
    }
    if(c == '.'){   //collect fraction part
        while(isdigit(s[++i] = c = getch())){
            ;
        }
    }
    s[i] = '\0';
    if(c != EOF){
        ungetch(c);
    }
    return NUMBER;
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