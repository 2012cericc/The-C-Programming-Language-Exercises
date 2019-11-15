// Exercise on page 49
#include <stdio.h>
/*
return x with n bits starting at p inverted, leave other unchanged
*/

unsigned invert(unsigned x, int p, int n);

int main(){
	unsigned x = 0b10101;
	int n = 3;
	int p = 4;

	printf("%x\n", invert(x, p, n));

	return 0;
}

unsigned invert(unsigned x, int p, int n){

	return x ^ (~(~0 << n) << (p-n));
}