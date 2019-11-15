// Exercise on page 46
#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

int main(){
	char s[] = "0xff";

	printf("hex: %s equals integer: %d\n", s, htoi(s));
	return 0;
}

int htoi(char s[]){
	int n = 0;

	for(int i=2; s[i]!='\0'; ++i){
		int curr;

		if(isdigit(s[i])){
			curr = s[i] - '0';
		}else{				// s[i] is a letter
			curr = (toupper(s[i]) - 'A') + 10;
		}
		n = n * 16 + curr;
	}
	return n;
}