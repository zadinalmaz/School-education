#include <stdio.h>

int sum(int a, int b);
int dif(int a, int b);
int work(int a, int b);
int del(int a, int b);

int main()
{
   
    float x, y;
     scanf("%f%f", &x, &y);
        
    if (x > (int)x || y > (int)y) {
        printf("n/a \n");}
        else
        { if (y==0){
            printf("%d %d %d n/a \n", sum(x, y), dif(x, y), work(x, y));}
            
            else
            {printf("%d %d %d %d\n", sum(x, y), dif(x, y), work(x, y), del(x, y));}}}

    int sum(int a, int b)
    {
    return (a + b);
}
    int dif(int a, int b)
    {
        return (a - b);
    }
    int work(int a, int b)
    {
        return (a * b);
    }
    int del(int a, int b)
    {
        return (a / b);
    }

    
  
