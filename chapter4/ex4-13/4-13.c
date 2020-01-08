// Exercise on page 88

/*
############################################################################
new options for this exercise
    Write a recursive version reverse(s), which reverses string s in place.
############################################################################
*/

#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main(){
    char s[] = "ABCDEFG";
    reverse(s);
    printf("reverse: %s\n", s);

    return 0;
}

void reverse(char s[]){
    void reverser(char s[], int i, int len);
    int i = 0;
    reverser(s, i, strlen(s));
}

void reverser(char s[], int i, int len){
    if(i <= len/2){
        char temp = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = temp;

        reverser(s, ++i, len);
    }
}

