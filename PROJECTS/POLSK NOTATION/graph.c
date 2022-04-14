#include "graph.h"
#include <string.h>
#include <math.h>
#include <stdio.h>

void null_matrica(int matrica[][M]) {
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < M; j++)
            matrica[i][j] = 0;
}


void print_pole(const char *s, double (*f)(const char *, const double)) {
    int matrica[N][M];
    null_matrica(matrica);
    double x_y[2][M];
    double x_step = (double) (_MAX_X - _MIN_X) / (double) (M - 1);
    double y_step = (double) (_MAX_Y - _MIN_Y) / (double) (N - 1);
    for (size_t i = 0; i < M; i++) {
        x_y[0][i] = _MIN_X + (double) i * x_step;
        x_y[1][i] = f(s, x_y[0][i]);
    }
    double y_a[N];
    for (size_t i = 0; i < N; i++)
        y_a[i] = _MIN_Y + (double) i * y_step;
    for (size_t x = 0; x < M; x++) {
        for (size_t y = 0; y < N - 1; y++) {
            if (x_y[1][x] >= y_a[y] && x_y[1][x] <= y_a[y + 1]) {
                if (x_y[1][x] < (y_a[y] + y_a[y + 1]) / 2)
                    matrica[y][x] = 1;
                else
                    matrica[y + 1][x] = 1;
            }
        }
    }
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) {
                if (matrica[i][j] == 1)
                    printf("*");
                else
                    printf(".");
            }
        if (i != N - 1)
            printf("\n");
    }
}
