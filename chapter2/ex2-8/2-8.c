// Exercise on page 49
#include <stdio.h>

/*
returns integer x rotated to the right by n bit positions
*/

unsigned rightrot(unsigned x, int n);
int wordsize();

int main(){
	unsigned x = 0b11000;
	int n = 2;

	printf("%x\n", rightrot(x, n));
	return 0;
}

unsigned rightrot(unsigned x, int n){
	int word = wordsize();
	int lsb;

	for(int i=0; i<n; ++i){
		int msb = (x & ~0) << (word - 1);
		x = x >> 1;
		x = x | msb;
	}

	return x;
}

int wordsize(){		// find word size on current machine
	int size = 0;
	unsigned v = ~0;

	while(v != 0){
		v = v << 1;
		++size;
	}
	return size;
}