// exercise on page 34
#include <stdio.h>

#define CPP_COMMENT 0
#define C_COMMENT 1

int main(){
	int c;
	int d;

	int prev = 0;

	int type; 
	int in_comment = 0;
	
	while((c=getchar()) != EOF){
		if(in_comment){				// in a comment
			if(c=='\n'){
				in_comment = 0;
				c = 0;
			}else if(prev=='*' && c=='/'){
				in_comment = 0;
				c = 0;
			}
			prev = c;
		}else{						// not in a comment

			if(prev=='/' && c=='*'){		// start of C_COMMENT
				type = C_COMMENT;
				in_comment = 1;
			}else if(prev=='/' && c=='/'){		// start of CPP_COMMENT
				type = C_COMMENT;
				in_comment = 1;
			}else if(c=='/'){
				prev = c;
			}else if(prev=='/'){
				putchar(prev);
				putchar(c);
				prev = c;
			}else{
				putchar(c);
			}
		}
	}

	return 0;
}



/*
notes
if "//", comment ends at '\n'
if "/*", comment ends at closing multi-line comment bracket

in_comment
	* / or \n
not in_comment
	/* or //
	A/, /A, 

read in c
if in_comment and type==CPP_COMMENT
	if c == \n
		in_comment = 0
else if in_comment and type == C_COMMENT
	if prev=='*' and c=='/'
		in_comment = 0

if prev=='/'' and c=='/'
	type = CPP_COMMENT
	in_comment = 1
else if prev=='/' and c=='*'
	type = C_COMMENT
	in_comment = 1


prev = c 

*/