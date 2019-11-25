// Exercise on page 63
#include <stdio.h>

void expand(char s1[], char s2[]);

int main(){
    char s1[100] = "a-h0-9";
    char s2[100];

    expand(s1, s2);

    printf("%s\n", s2);
    return 0;
}

void expand(char s1[], char s2[]){      // s1 = shorthand, s2 = expanded
    char c;

    int i = 0;      // s1 index
    int j = 0;      // s2 index

    while(s1[i] != '\0'){
        c = s1[i];

        if(s1[i+1]=='-'){
            while(c<=s1[i+2]){
                s2[j] = c;
                ++c;
                ++j;
            }
            i += 2;
        }else{
            ++i;
        }
    }
    s2[j] = '\0';
}