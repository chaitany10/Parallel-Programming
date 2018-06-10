#include<stdio.h>
#include<omp.h>

int main()
{
	int Noofintervals=1000000, i;
	float sum, x, totalsum, dx, partialsum, sumthread;

	sum = 0.0;
	dx = 1.0 / (double)Noofintervals;



#pragma omp parallel 
	for (i = 1; i < Noofintervals + 1; i = i + 1) {
		x = dx * (i - 0.5);

		sumthread = sumthread + 4.0 / (1 + x * x);
	}
	partialsum = sumthread * dx;

	sum = sum + partialsum;

	printf("The value of PI is %d\n", sum);
}
