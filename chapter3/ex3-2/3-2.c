// Exercise on page 60
#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(){
	char s[100] = "AA\n\tB\\B\t";	// s[] contains newlines and tabs
	char t[100];				// t[] contains escape sequences

	printf("before escape: %s\n", s);
	escape(s, t);
	printf("after escape: %s\n", t);

	printf("\n");

	printf("before unescape: %s\n", t);
	unescape(s, t);
	printf("after unescape: %s\n", s);

	return 0;
}

void escape(char s[], char t[]){		// convert newline, tabs into escape sequences
	int i;		// s[] index
	int j = 0;	// t[] index

	for(int i=0; s[i]!='\0'; ++i){
		switch(s[i]){
			case '\n':
				t[j] = '\\';
				t[j + 1] = 'n';
				j = j + 2;
				break;
			case '\t':
				t[j] = '\\';
				t[j + 1] = 't';
				j = j + 2;
				break;
			default:
				t[j] = s[i];
				++j;
		}
	}
	t[j] = '\0';
}

void unescape(char s[], char t[]){		// convert escape sequences into newline, tabs
	int i = 0;	// s[] index
	int j = 0;	// t[] index

	for(j=0; t[j]!='\0'; ++j){
		if(t[j] == '\\'){
			++j;
			switch(t[j]){
				case 'n':
					s[i] = '\n';
					++i;
					break;
				case 't':
					s[i] = '\t';
					++i;
					break;
				default:
					s[i] = t[j-1];	// not an esc sequence
					++i;
					s[i] = t[j];
					++i;
			}
		}else{
			s[i] = t[j];
			++i;
		}
	}
	s[i] = '\0';
}