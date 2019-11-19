// Exercise on page 58
#include <stdio.h>

int binsearch(int x, int v[], int n);
int binsearch_orig(int x, int v[], int n);

int main(){
	int v[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	int n = 11;
	int x = 10;

	printf("%d\n", binsearch(x, v, n));
	return 0;
}

int binsearch(int x, int v[], int n){		
	int low = 0;
	int high = n - 1;
	int mid;
     
	while(low <= high && v[mid]!=x){
		mid = (low + high) / 2;
		if(x < v[mid]){
			high = mid - 1;
		}else{
			low = mid + 1;
	    }
	}

	if(v[mid] == x){
		return mid;
	}else{
		return -1;
	}
}

int binsearch_orig(int x, int v[], int n){		// code from text
	int low = 0;
	int high = n - 1;
	int mid;

	while(low <= high){
		mid = (low + high) / 2;
		if(x < v[mid]){
			high = mid -1;
		}else if(x > v[mid]){
			low = mid + 1;
		}else{
			return mid;
		}
	}
	return -1;
}