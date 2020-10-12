#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NTIMES 100000000

float iSqrt_asml(float x);
float iSqrt_asm(float x);
float iSqrt_lib(float x);
float iSqrt(float x);

int main(int argc, char *argv[])
{
	float num1 = 35.0f;
	int time1 = 0;
	int time2 = 0;
	double t1, t2, t3, t4;
	printf("****************************Introduction********************************\n");
	printf("iSqrt_asml(): Asm func, using fsqrt instruction, with optimization.\n");
	printf("iSqrt_asm(): Asm func, using Carmack Algorithm, with optimization.\n");
	printf("iSqrt_lib(): C func, calculate 1.0 / sqrt(x), with option -O2.\n");
	printf("iSqrt(): C func, using Carmack Algorithm, with option -O2.\n");

	printf("*******************************Result***********************************\n");
	printf("iSqrt_asml(%lf) = %lf\n", num1, iSqrt_asml(num1));
	printf("iSqrt_asm(%lf) = %lf\n", num1, iSqrt_asm(num1));
	printf("iSqrt_lib(%lf) = %lf\n", num1, iSqrt_lib(num1));
	printf("iSqrt(%lf) = %lf\n", num1, iSqrt(num1));
	
	printf("********************************Time************************************\n");
	time1 = clock();
	for(int i = 0; i < NTIMES; iSqrt_asml(num1), ++i);
	time2 = clock();
	printf("Run %d times iSqrt_asml(), t1 = %lf\n", NTIMES, t1 = (double)(time2 - time1) / CLOCKS_PER_SEC);
	
	time1 = clock();
	for(int i = 0; i < NTIMES; iSqrt_asm(num1), ++i);
	time2 = clock();
	printf("Run %d times iSqrt_asm(), t2 = %lf\n", NTIMES, t2 = (double)(time2 - time1) / CLOCKS_PER_SEC);

	time1 = clock();
	for(int i = 0; i < NTIMES; iSqrt_lib(num1), ++i);
	time2 = clock();
	printf("Run %d times iSqrt_lib(), t3 = %lf\n", NTIMES, t3 = (double)(time2 - time1) / CLOCKS_PER_SEC);
	
	time1 = clock();
	for(int i = 0; i < NTIMES; iSqrt(num1), ++i);
	time2 = clock();
	printf("Run %d times iSqrt(), t4 = %lf\n", NTIMES, t4 = (double)(time2 - time1) / CLOCKS_PER_SEC);

	printf("*****************************Percentage*********************************\n");
	printf("t2 / t1 = %lf\n", t2 / t1);
	printf("t4 / t3 = %lf\n", t4 / t3);
	printf("t2 / t4 = %lf\n", t2 / t4);
	return 0;
}

