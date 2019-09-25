// exercise on page 13
#include <stdio.h>

/* print Celsius-Fahrenheit table
	for fahr = 0, 20, ..., 300; floating-point version */

int main(){
	float fahr;
	float celsius;

	int lower = 0;
	int upper = 300;
	int step = 20;

	celsius = lower;
	printf("Cels Fahr\n");
	while(celsius <= upper){
		fahr = (9.0/5.0) * celsius + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr); // print fahr 3 chars wide, no decimals
		celsius = celsius + step;
	}
}
