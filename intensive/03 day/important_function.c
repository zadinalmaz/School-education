#include <stdio.h>
#include <math.h>

float calculation(float x);


int main()
{ 
	float x;

	if (scanf("%f", &x) != 1)
	{
		printf("n/a\n");
	}
	else 
	{
	    float z = calculation(x);
	    printf("%.1f\n", z);
	}
}

float calculation(float x)
{
   return (7 * powf(10, -3) * powf(x,4) + ((22.8 * powf(x, 1/3) - powf(10, 3)) * x + 3) / (x * x / 2) - x * powf(10+x, 2/x) - 1.01);
}
