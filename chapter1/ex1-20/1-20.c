// exercise on page 34
#include <stdio.h>

#define TABSTOP 4

int main(){
	int c;
	int width = 0;

	while((c=getchar()) != EOF){
		if(c == '\t'){			// fill out rest of width with spaces and reset width
			for(; width<TABSTOP; ++width){
				putchar(' ');
			}
			width = 0;
		}else if(c == '\n'){	// reset width after newline
			width = 0;
		}else{					//print char and increment width counter
			
			putchar(c);
			++width;
		}
		if(width >= TABSTOP){ 	// reset width counter
			width = 0;
		}
	}
	return 0;
}

/*
notes
01230123
A	B
A...B
*/