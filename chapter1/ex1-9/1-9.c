// exercise on page 20
#include <stdio.h>

int main(){
	int c;

	while((c=getchar()) != EOF){
		if(c == ' '){
			while((c=getchar()) == ' '){
				;
			}
			putchar(' ');
			if(c == EOF){
				break; // break statements might not have been introduced yet
			}
		}
		putchar(c);
	}
}

/*
// testing out the official answer for comparison

#define NONBLANK 'a'

int main(){
	int c;
	int lastc = NONBLANK;

	while((c=getchar()) != EOF){
		if(c != ' '){
			putchar(c);
		}

		if(c == ' '){
			if(lastc != ' '){
				putchar(c);
			}
		}
		lastc = c;
	}
}
*/