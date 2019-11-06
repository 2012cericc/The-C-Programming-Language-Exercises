// exercise on page 20
#include <stdio.h>

int main(){
	int count = 0;
	int c;

	while((c=getchar()) != EOF){
		if(c == ' '){
			++count;
		}
		if(c == '\t'){
			++count;
		}
		if(c == '\n'){
			++count;
		}
	}
	printf("%d\n", count);
}