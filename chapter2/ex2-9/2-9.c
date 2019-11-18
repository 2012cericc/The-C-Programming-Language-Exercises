// Exercise on page 51
#include <stdio.h>

int bitcount(unsigned x);

int main(){
	unsigned x = 0b10101011;

	printf("%d\n", bitcount(x));
	return 0;
}

int bitcount(unsigned x){
	int b;

	for(b=0; x!=0; x&=x-1){
		++b;
	}
	return b;
}
