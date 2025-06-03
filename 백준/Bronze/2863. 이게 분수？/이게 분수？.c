#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(x,y) (x) > (y) ? x : y 

double calc(double a, double b, double c, double d)
{
	return a/c + b/d;
}

int main()
{
	double a, b, c, d;
	double mx = 0;
	int mxI;
	
	scanf("%lf %lf\n%lf %lf", &a, &b, &c, &d);
	for (int i = 0; i < 4; i++)
	{
		if (calc(a, b, c, d) > mx)
		{
			mx = calc(a, b, c, d);
			mxI = i;
		}
		double tmp = a;
		a = c;
		c = d;
		d = b;
		b = tmp;
	}
	printf("%d", mxI);
}