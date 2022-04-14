#include <stdio.h>
#define NMAX 10
void input (int *a, int n);
int main() {
    int n = NMAX;
    int i, j;
    int data[NMAX];
    input (data, n);
   
}

void input (int *a, int n) {
     for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}