// exercise on page 42
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(){
	int c;
	int i = 0;
	int lim = 100;
	int cont = TRUE; // continue
	char s[lim];

	while(cont == TRUE){
		if(i >= lim-1){
			cont = FALSE;
		}else if((c=getchar()) == '\n'){
			cont = FALSE;
		}else if(c == EOF){
			cont = FALSE;
		}else{
			s[i] = c;
			++i;
		}
	}
	s[i] = '\0';

	printf("%s", s);
}