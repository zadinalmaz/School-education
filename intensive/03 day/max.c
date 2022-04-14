#include <stdio.h>

int max(int a, int b);

int main()
{
    float x, y;
    scanf("%f%f", &x, &y);
    int z = max(x, y);
if (x - (float)(int)x == 0 && (y - (float)(int)y == 0)) {
    printf("%d\n", z); }
else
{ printf("n/a \n");
 }}
int max(int a, int b)
{ int m = a;
    if(b > a) {
        m = b;}
        return m;}
