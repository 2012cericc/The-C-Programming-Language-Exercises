// exercise on page 34
#include <stdio.h>
#define MAXLEN 80
#define TABSTOP 8

void print_word(char word[], int len);

int main(){
	int c;
	char word[MAXLEN];
	int wordlen = 0;		// num chars in word
	int equiv_wordlen = 0;	// num of spaces occupied by word, tabs can be > 1 blank
	int linelen = 0;		// total length of line with equiv spaces occupied by tabs

	while((c=getchar()) != EOF){
		// if word == MAXLEN, print it, newline, other chars, reset counters
		if(equiv_wordlen == MAXLEN){
			print_word(word, wordlen);
			putchar('\n');
			wordlen = 0;
			equiv_wordlen = 0;
			linelen = 0;
		}

		if(c == ' '){
			// symbolizes end of word
			// check wordlen+linelen > MAXLEN
			word[wordlen] = c;
			++wordlen;
			++equiv_wordlen;

			if(equiv_wordlen + linelen > MAXLEN){	// print word on newline
				putchar('\n');
				print_word(word, wordlen);
				linelen = equiv_wordlen;
				equiv_wordlen = 0;
				wordlen = 0;
			}else{									// print word on same line
				print_word(word, wordlen);
				linelen += equiv_wordlen;
				equiv_wordlen = 0;
				wordlen = 0;
			}

		}else if(c == '\n'){
			// premature move to newline
			// check wordlen+linelen > MAXLEN
			word[wordlen] = c;
			++wordlen;
			++equiv_wordlen;

			if(equiv_wordlen + linelen > MAXLEN){	// print word on newline
				putchar('\n');
				print_word(word, wordlen);
				linelen = equiv_wordlen;
				equiv_wordlen = 0;
				wordlen = 0;
			}else{									// print word on same line
				print_word(word, wordlen);
				linelen = 0;
				equiv_wordlen = 0;
				wordlen = 0;
			}

		}else if(c == '\t'){
			// add tabwidth in equivalent num spaces occupied by tab
			int tabwidth = TABSTOP - ((linelen+equiv_wordlen) % TABSTOP);
			equiv_wordlen += tabwidth;
			word[wordlen] = c;
			++wordlen;

			if(equiv_wordlen + linelen > MAXLEN){	// print word on newline
				putchar('\n');
				print_word(word, wordlen);
				linelen = equiv_wordlen;
				equiv_wordlen = 0;
				wordlen = 0;
			}else{									// print word on same line
				print_word(word, wordlen);
				linelen += equiv_wordlen;
				equiv_wordlen = 0;
				wordlen = 0;
			}
		}else{
			// not a special character
			word[wordlen] = c;
			++wordlen;
			++equiv_wordlen;
		}
	}
}

void print_word(char word[], int len){
	for(int i=0; i<len; ++i){
		putchar(word[i]);
	}
}

/*
notes
word longer than MAXLEN
	truncate
word ends in '\n'
	print newline, restart counters
word ends in '\t'
	determine tabwidth, add width to counters
word ends in ' '

aaaa bbbb
aaaa 
bbbb

*/