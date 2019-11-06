// exercise on page 31
#include <stdio.h>
#define MINLINE 10 //print lines that are > TARGETLINE
#define MAXLINE 1000 // max input line size

int getline_custom(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
	int len;
	char line[MAXLINE];

	while((len=getline_custom(line, MAXLINE)) > 0){
		if(len > MINLINE){
			printf("%s", line);
		}
	}

	return 0;
}

int getline_custom(char s[], int lim){
	int c, i;

	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){
		s[i] = c;
	}
	if(c == '\n'){
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[]){
	int i = 0;

	while((to[i] = from[i]) != '\0'){
		++i;
	}
}