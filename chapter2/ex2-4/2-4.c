// Exercise on page 48
#include <stdio.h>

#define TRUE 1
#define FALSE 0

void squeeze(char s1[], char s2[]);
int search(char c, char s2[]);

int main(){
	char s[] = "AFEBRCJSKQGD";				// Unique chars = ABCD
	char t[] = "EFGHIJKLMNOPQRSTUVWXYZ";

	squeeze(s, t);

	printf("%s\n", s);
	return 0;
}

void squeeze(char s1[], char s2[]){
	int i;
	int j;
	for(i=j=0; s1[i]!='\0'; ++i){
		if(!search(s1[i], s2)){
			s1[j] = s1[i];
			j++;
		}
	}
	s1[j] = '\0';
}

int search(char c, char s2[]){
	int i;

	for(i=0; s2[i]!='\0'; ++i){
		if(s2[i] == c){
			return TRUE;
		}
	}
	return FALSE;
}