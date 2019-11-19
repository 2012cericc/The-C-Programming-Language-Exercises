// Exercise on page 51
#include <stdio.h>

int lower(int c);

int main(){
	int c = 'B';

	printf("before: %c\n", c);
	printf("after : %c\n", lower(c));

	return 0;
}

int lower(int c){
	c = (c >= 'A' && c <= 'Z') ? (c+'a'-'A') : c;
	return c;
}