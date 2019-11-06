// exercise on page 34
#include <stdio.h>

#define true 1
#define false 0

int main(){
	int c;
	int prev;

	int skip = false;

	int para = 0;
	int brack = 0;
	int brace = 0;
	int sin_quote = 0;
	int doub_quote = 0;
	int comment = 0;

	while((c=getchar()) != EOF){
		if(!skip){
			if((prev=='/' && c=='*') || (prev=='*' && c=='/')){			// start or end comment
				skip = true;
				c = 0;
				++comment;
			}else if(prev=='\\' && c=='\''){							// escape singlequote
				skip = true;
				//c = 0;
			}else if(prev=='\\' && c== '\"'){							// escape doublequote
				skip = true;
				//c = 0;
			}else if(prev=='(' || prev==')'){							// open or close parenthesis
				++para;
			}else if(prev=='{' || prev=='}'){							// open or close brace
				++brace;
			}else if(prev=='[' || prev==']'){							// open or close bracket
				++brack;
			}else if(prev=='\''){										// single quote
				++sin_quote;
			}else if(prev=='\"'){										// double quote
				++doub_quote;
			}
		}else{
			skip = false;
		}

		
		prev = c;
	}
	printf("\n");

	if(para % 2 == 1){
		printf("Unbalanced parenthesis\n");
	}
	if(brack % 2 ==1){
		printf("Unbalanced brackets\n");
	}
	if(brace % 2 ==1){
		printf("Unbalanced braces\n");
	}
	if(sin_quote % 2 ==1){
		printf("Unbalanced single quotes\n");
	}
	if(doub_quote % 2 ==1){
		printf("Unbalanced double quotes\n");
	}
	if(comment % 2 ==1){
		printf("Unbalanced comments\n");
	}
}

/*
notes

parenthesis 		( )
brackets			[ ]
braces quotes		{ }
	single			' '
	double			" "
escape sequences	\" does not count towards total
comments			/* * /

if c and prev
	if \' or \"
*/
