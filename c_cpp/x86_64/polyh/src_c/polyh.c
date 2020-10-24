/* Apply Horner's method */
double polyh(double a[], double x, long degree)
{
	long i;
	double result = a[degree];
	for(i = degree - 1; i >= 0; --i)
		result = a[i] + x * result;
	return result;
}
