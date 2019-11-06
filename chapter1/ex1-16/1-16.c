// exercise on page 30
#include <stdio.h>
#define MAXLINE 1000 // max input line size

int getline_custom(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
	int len;
	char line[MAXLINE];

	while((len=getline_custom(line, MAXLINE)) > 0){
		printf("len: %d, %s\n", len, line);
	}
	return 0;
}

int getline_custom(char s[], int lim){
	int c;
	int lastc;

	int i;			// tracks length of line, can be > MAXLINE
	int j = 0;		// tracks char position in array

	for(i=0; (c=getchar())!=EOF && c!='\n'; ++i){
		if(i == lim-2){		// save 2nd to last char in case there is no newline
			lastc = c;
		}
		
		if(i < lim-2){		// leave space for potential newline and null byte
			s[j] = c;
			++j;
		}
	}

	if(c == '\n'){			// reinsert newline if the forloop was broken by newline
		s[j] = c;
		++j;
		++i;				// count the newline from the input

	}else if(i > lim-2){		// no newline, but input is > lim-2, insert 2nd to last char
		s[j] = lastc;			// where the newline would have went to maximize length
		++j;
	}
	s[j] = '\0';
	
	return i;
}

void copy(char to[], char from[]){
	int i = 0;

	while((to[i] = from[i]) != '\0'){
		++i;
	}
}