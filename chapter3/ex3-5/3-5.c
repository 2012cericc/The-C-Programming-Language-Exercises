// Exercise on page 64
#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(){
    char s[100];
    int n = 255;

    itob(n, s, 16);
    printf("%s\n", s);

    return 0;
}

// convert n into a base b (16 bit) string
void itob(int n, char s[], int b){
    int i = 0;
    int sign;

    if(n < 0){
        sign = -1;
        n = -n;
    }

    do{
        (n % b) <= 9  ? (s[i++] = n%b + '0') : (s[i++] = (n%b-10) + 'A');
    }while((n/=b) != 0);

    if(sign < 0){
        s[i++] = '-';
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