// Exercise on page 79
// needs to be compiled as "gcc 4-6.c -lm -o 4-6"

/*
############################################################################
new options for this exercise
    Starting with the base code from the text, "add commands to handle
    variables. Add a variable for the most recently printed value".

    Prompt was interpreted to mean that whenever a value is printed, it
    will be assigned a single letter variable (a, b, c, ...).
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
int getch(void);
void ungetch(int);

int sp = 0;         // next free stack position
double val[MAXVAL]; // value stack
char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       //next free position in buf


// reverse polish calculator
int main(){
    int type;
    double op2;
    char s[MAXOP];

    // NEW: variables and most recently printed value
    int var = 0;
    double variable[26];
    for(int i=0; i<26; ++i){
        variable[i] = 0.0;
    }

    double v;  //most recent printed value

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
            // NEW: '=' and default behavior
            case '=':
                pop();
                if(var >= 'A' && var <= 'Z'){
                    variable[var-'A'] = pop();
                }else{
                    printf("error: no variable name\n");
                }
                break;
            case '\n':
                v = pop();
                printf("\t%.8g\n", v);
                break;
            default:
                if(type >= 'A' && type <= 'Z'){
                    push(variable[type-'A']);
                }else if(type == 'v'){
                    push(v);
                }else{
                    printf("error: unknown command %s\n", s);
                }
                break;
        }
        var = type;
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
    if(!isdigit(c) && c != '.'){
        return c;
    }
    i = 0;
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