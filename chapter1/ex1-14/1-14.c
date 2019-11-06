// exercise on page 24
#include <stdio.h>
#include <ctype.h>

#define MAXCHARS 128 // max number of different ascii chars
#define MAXFREQ 20

int main(){
	int c;
	int histogram[MAXCHARS];

	for(int i=0; i<MAXCHARS; ++i){	// zero out array entries
		histogram[i] = 0;
	}

	while((c=getchar()) != EOF){	// read in chars
		if(c < MAXCHARS){
			++histogram[c];
		}
	}

	for(int i=0; i<MAXCHARS; ++i){	// don't let freqency get too large
		if(histogram[i] > MAXFREQ){
			histogram[i] = MAXFREQ;
		}
	}

	for(int i=0; i<MAXCHARS; ++i){
		if(isprint(i)){		// only print histogram of printable chars
			printf("\'%c\': ", i);

			for(int j=0; j<histogram[i]; ++j){
				printf("*");
			}

			printf("\n");
		}
	}
}