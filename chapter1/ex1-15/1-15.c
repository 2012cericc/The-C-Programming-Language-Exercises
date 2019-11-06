// exercise on page 27
#include <stdio.h>

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300; floating-point version using functions */
float fahrToCels(float fahr);

int main(){
	float fahr;
	float celsius;

	int lower = 0;
	int upper = 300;
	int step = 20;

	fahr = lower;
	printf("Fahr Cels\n");
	while(fahr <= upper){
		celsius = fahrToCels(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius); // print fahr 3 chars wide, no decimals
		fahr = fahr + step;
	}
	return 0;
}

float fahrToCels(float fahr){
	return (5.0/9.0) * (fahr-32.0);
}