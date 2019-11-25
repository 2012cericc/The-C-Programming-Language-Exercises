// Exercise on page 64
#include <stdio.h>
#include <string.h>

#define abs(x) (x<0 ? -(x) : (x))

void itoa(int n, char sp[]);
void itoa_original(int n, char sp[]);
void reverse(char s[]);

int main(){
    char s_orig[100];
    char s[100];
    int n = -2147483648;    // -(2^(32-1))

    itoa_original(n, s_orig);
    itoa(n, s);

    printf("orig: %s\n", s_orig);
    printf("new:  %s\n", s);
    return 0;
}

// convert number to char string
void itoa(int n, char s[]){
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

    s[i] = '\0';
    reverse(s);
}

// original function from the text
void itoa_original(int n, char s[]){
    int i;
    int sign;

    if((sign=n)<0){     // ensure n is positive
        n = -n;
    }

    i = 0;
    do{
        s[i++] = n % 10 + '0';
    }while((n/=10) > 0);

    if(sign < 0){
        s[i++] = '-';
    }

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]){
    int c;
    int i;
    int j;

    for(i=0, j=strlen(s)-1; i<j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}