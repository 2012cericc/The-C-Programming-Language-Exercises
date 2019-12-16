// Exercise on page 71
#include <stdio.h>
#define MAXLINE 1000

int getline_custom(char s[], int max);
int strrindex(char s[], char t[]);

char pattern[] = "AA";

int main(){
    char line[MAXLINE];
    int pos;

    while(getline_custom(line, MAXLINE) > 0){
        pos = strrindex(line, pattern);
        if(pos >= 0){
            printf("occurance: %d, %s\n", pos, line);
        }
    }

    return 0;
}

// get line into s, return length
int getline_custom(char s[], int lim){
    int c;
    int i = 0;

    while(--lim>0 && (c=getchar())!=EOF && c!='\n'){
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int strrindex(char s[], char t[]){
    int i;
    int j;
    int k;
    int pos;
    
    for(int i=0; s[i]!='\0'; i++){
        for(j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++){
            ;
        }
        if(k>0 && t[k]=='\0'){
            pos = i;
        }
    }
    if(pos >= 0){
        return pos;
    }else{
        return -1;
    }
}