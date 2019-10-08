#include <stdio.h>
#define MAXLINE 1000

int getline_custom(char line[], int maxline);
void reverse(char line[], int length);

int main(){
	char line[MAXLINE];
	int len;
	while((len=getline_custom(line, MAXLINE)) > 0){
		
		reverse(line, len);
		printf("%s", line);
	}

	return 0;
}

int getline_custom(char s[], int lim){
	int c, i;

	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){
		s[i] = c;
	}
	if(c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void reverse(char s[], int len){
	char temp;
	int num_swaps = (len-1)/2;	// number of iterations

	for(int i=0; i<num_swaps; ++i){		// swap chars from front/back
		temp = s[i];
		s[i] = s[len-2-i];
		s[len-2-i] = temp;
	}
}