
#include "Function.h"

int summ(int a, int b)
{
	int c = a + b;
	return c;
}
int minus(int a, int b)
{
	int c = a - b;
	return c;
}
int mult(int a, int b)
{
	int c = a*b;
	return c;
}
int max(int a, int b)
{
	int c;
	a > b ? c=a : c=b;
	return c;
}
int min(int a, int b)
{
	int c;
	a < b ? c = a : c = b;
	return c;
}
int triangle(int a, int b)
{

	int c =(a*a+b*b);
	return c;
}