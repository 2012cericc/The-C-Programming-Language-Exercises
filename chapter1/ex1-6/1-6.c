// exercise on page 17
#include <stdio.h>

int main(){
	int c;

	c = getchar() != EOF;

	printf("c: %d\n", c); // prints 0 if c is EOF, 1 if c is not EOF
}