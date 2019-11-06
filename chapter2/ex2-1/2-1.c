// exercise on page 36
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	printf("headers\n");
	printf("schar %d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("uchar %d to %d\n", 0, UCHAR_MAX);

	printf("sshort %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("ushort %d to %d\n", 0, USHRT_MAX);

	printf("sint %d to %d\n", INT_MIN, INT_MAX);
	printf("uint %d to %u\n", 0, UINT_MAX);

	printf("slong %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("ulong %d to %lu\n", 0, ULONG_MAX);

	printf("\n");

	prinf("calculated\n");
	printf("schar %d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("uchar %d to %d\n", 0, UCHAR_MAX);

	printf("sshort %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("ushort %d to %d\n", 0, USHRT_MAX);

	printf("sint %d to %d\n", INT_MIN, INT_MAX);
	printf("uint %d to %u\n", 0, UINT_MAX);

	printf("slong %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("ulong %d to %lu\n", 0, ULONG_MAX);

	return 0;
}

/*
notes
ranges of signed/unsigned
	char
	short
	int
	long

*/