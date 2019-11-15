// Exercise on page 49
#include <stdio.h>

/*
return x with n bits starting at position p set to rightmost n bits of y
leaving other bit unchanged
*/

int setbits(unsigned x, int p, int n, unsigned y);

int main(){
	unsigned x = 0x2D;	// 0b101101
	int p = 5;
	int n = 4;
	unsigned y = 0xf;	//0b1111

	printf("%x\n", setbits(x, p, n, y)); //result should be 0b111111


	return 0;
}


unsigned setbits(unsigned x, int p, int n, unsigned y){
	unsigned ybits = y & ~(~0 << n);	// isolate rightmost n bits of y
	unsigned ymask = ybits << (p-n);	// shift the bits to the correct position

	unsigned clearx = x & ~(~(~0<<n) << (p-n));	// clear n bits starting at p in x
	
	return clearx | ymask;
}