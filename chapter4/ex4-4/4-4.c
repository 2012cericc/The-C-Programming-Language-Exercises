// Exercise on page 79
// needs to be compiled as "gcc 4-4.c -lm -o 4-4" to use fmod()
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // for atof()
#include <math.h>

#define MAXOP 100   // max size of operand or operator
#define MAXVAL 100  // max depth of val stack
#define NUMBER '0'  // signal that a number was found
#define BUFSIZE 100

void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);

int sp = 0; // next free stack position
double val[MAXVAL]; // value stack
char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;   //next free position in buf

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
            /*
            ############################################################################
            new options for this exercise
                -print top element without popping  (peek)
                -clear the stack                    (clear)
                -duplicate top elements             (dup)
                -swap top two elements              (swap)
            ############################################################################
            */
            case '?':   // peek top element
                op2 = pop();
                printf("\t%.8g\n", op2);
                push(op2);
                break;
            case 'c':   // clear stack
                sp = 0;
                break;
            case 'd':   // duplicate top element
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's':   // swap top two elements
                op1 = pop();
                op2 = pop();
                push(op1);
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

// getop: get next operator or numeric operand
int getop(char s[]){
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t'){
        ;
    }
    s[1] = '\0';
    if(!isdigit(c) && c != '.' && c != '-'){
        return c;   // not a number
    }

    i = 0;
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