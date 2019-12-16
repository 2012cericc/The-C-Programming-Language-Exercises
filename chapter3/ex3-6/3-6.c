// Exercise on page 64
#include <stdio.h>
#include <string.h>

#define abs(x) (x<0 ? -(x) : (x))

void reverse(char s[]);
void itoa(int n, char s[], int w);


int main(){
    char s[100];
    int n = -12345;
    int w = 8;

    itoa(n, s, w);
    printf("string: %s\n", s);

    return 0;
}

// convert number to char string of min length w
void itoa(int n, char s[], int w){
    int i;
    int sign;

    sign = n;

    i = 0;
    do{
        s[i++] = abs(n%10) + '0';
    }while((n/=10) != 0);

    if(sign < 0){
        s[i++] = '-';
    }

    while(i < w){       // pad the string to min width w
        s[i++] = ' ';
    }

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]){
    int c;
    int i;
    int len = strlen(s);

    for(i=0; i<len/2; ++i){
        c = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = c;
    }
}