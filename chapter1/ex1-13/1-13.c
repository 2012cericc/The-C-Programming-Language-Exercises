// exercise on page 24
#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLEN 20

int main(){
	int histogram[MAXLEN];
	int c, state, wordLen;

	state = OUT;
	wordLen = 0;

	for(int i=0; i<MAXLEN; ++i){ 				// zero out array entries
		histogram[i] = 0;
	}
	
	while((c=getchar()) != EOF){
		if(c != ' ' && c != '\n' && c != '\t'){ // in a word
			state = IN;
			++wordLen;
		}else if(state == IN){ 					// finish a word
			state = OUT;
			++histogram[wordLen];				// save and reset wordLen
			wordLen = 0;
		}
	}

	printf("Histogram\n");
	for(int i=1; i<MAXLEN; ++i){
		printf("%02d: ", i);

		for(int j=0; j<histogram[i]; ++j){
			printf("*");
		}
		printf("\n");
	}
}