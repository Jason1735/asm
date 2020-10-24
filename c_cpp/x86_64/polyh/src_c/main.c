#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NTIMES 1000000
#define DEGREE 329
extern double poly(double a[], double x, long degree);
extern double polyh(double a[], double x, long degree);


int main(int argc, char *argv[])
{
	int time1 = 0;
	int time2 = 0;
	double t1 = 0.0;
	double t2 = 0.0;
	double a[DEGREE+1] = {
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12, 
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12, 
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12, 
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12, 
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12, 
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12, 
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12, 
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12, 
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12, 
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12,  
		1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12}; 
	double x = 0.891;
	double result = 0;
	time1 = clock();
	for(int i = 0; i < NTIMES; result = poly(a, x, DEGREE), ++i);
	time2 = clock();
	printf("poly: %f\n", t1 = ((double)time2 - time1) / CLOCKS_PER_SEC);

	time1 = clock();
	for(int i = 0; i < NTIMES; result = polyh(a, x, DEGREE), ++i);
	time2 = clock();
	printf("polyh: %f\n", t2 = ((double)time2 - time1) / CLOCKS_PER_SEC);
	printf("t1 / t2 = %f\n", t1 / t2);
	return 0;
}
