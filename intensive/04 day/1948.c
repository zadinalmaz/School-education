
#include <stdio.h>
#include <math.h>
int division(int val, int integer);
int is_prime(int i);

int main() {
    float abc;
    scanf("%f", &abc);
    if (abc - (float)(int)abc !=0 || abc == 1) {
        printf("n/a\n");
    } else {
        int val;
        val = (int)abc;
    if (val < 0) {
        val = val * (-1);
    }
    for (int i = val; i > 0; i--) {
        if (division(val, i) && is_prime(i)) {
            printf("%d\n", i);
            return 0;
        }
    }}
    return 0;
}
int division(int val,  int integer) {
    while (val > 0) {
        val -= integer;
       // printf("%d", val);
        if (val == 0) {
            return 1;
        }
    }
    return 0;
}
int is_prime(int g) {
    int count = 0;
    for (int j = 1; j <= g; j++) {
        if (division(g, j)) {
            count++;
        }
    }
    if (count == 2) {
        return 1;
    } else {
            return 0;
        }}
