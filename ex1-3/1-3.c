// exercise on page 13
#include <stdio.h>

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300; floating-point version */

int main(){
	float fahr;
	float celsius;

	int lower = 0;
	int upper = 300;
	int step = 20;

	fahr = lower;
	printf("Fahr Cels\n");
	while(fahr <= upper){
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius); // print fahr 3 chars wide, no decimals
		fahr = fahr + step;
	}
}