// exercise on page 34
#include <stdio.h>
#define TABSTOP 8

int main(){
	int c;
	int counter = 0;
	int blank_count = 0;

	while((c=getchar()) != EOF){
		// input has reached TABSTOP in width
		if(counter == TABSTOP && blank_count > 0){	// replace trailing blanks with tab
			putchar('\t');
			counter = 0;
			blank_count = 0;
		}else if(counter == TABSTOP){				// no trailing blanks
			counter = 0;
			blank_count = 0;
		}

		if(c == '\t'){								// reset counters if tab
			putchar(c);
			counter = 0;
			blank_count = 0;
		}else if(c == '\n'){						// print trailing blanks before newline
			for(int i=0; i<blank_count; ++i){
				putchar(' ');
			}
			putchar(c);
			counter = 0;
			blank_count = 0;
		}else if(c == ' '){							// keep track of number of blanks since last letter
			++blank_count;
			++counter;
		}else{										// input is letter/num, print leading blanks
			for(int i=0; i<blank_count; ++i){
				putchar(' ');
			}
			putchar(c);
			blank_count = 0;						// reset blank counter
			++counter;
		}
	}
}


/*
notes

tab
space
letter/num

space tab - consolidate to single tab
space letter - print same
letter space - replace space with tab
letter space tab - consolidate to single tab

if space, count space
if letter
	print num spaces, then print letter
	reset blankcount
if tab
	print tab, reset counter/blankcount

*/