// exercise on page 31
#include <stdio.h>
#define MAXLINE 1000 // max input line size

int getline_custom(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
	int len;
	char line[MAXLINE];

	while((len=getline_custom(line, MAXLINE)) > 0){
		printf("%s", line);
	}

	return 0;
}

int getline_custom(char s[], int lim){
	int c, i;
	int last = 0; // array position of last non-blank

	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){
		s[i] = c;

		if(c != ' ' && c != '\t'){
			last = i;
		}
	}
	if(c == '\n'){
		s[i] = '\n';
		++i;
	}
	
	if(i){
		s[last+1] = '\0';
	}
	
	return i;
}

void copy(char to[], char from[]){
	int i = 0;

	while((to[i] = from[i]) != '\0'){
		++i;
	}
}