// exercise on page 21
#include <stdio.h>

#define IN 1
#define OUT 0

int main(){
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;

	while((c=getchar()) != EOF){
		++nc;
		if(c == '\n'){
			++nl;
		}
		if(c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
		}else if(state == OUT){
			state = IN;
			++nw;
		}
	}

	printf("\nnew line:%d\nnew word:%d\nnew char:%d\n", nl, nw, nc);
}

/*
some test cases:
	no input
	single char input
	multi char input
	multi single char words
	words + newline
	input with only blanks
	input starting with blanks
*/