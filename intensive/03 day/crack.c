#include <stdio.h>

int main()
{
	float x, y;
if (scanf("%f%f", &x, &y) ==2 && -5 < x && x < 5 && -5 < y && y < 5)
	printf("GOTCHA\n");
else 
	printf("MISS\n");
		return 0;}
