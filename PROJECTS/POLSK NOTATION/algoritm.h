#ifndef SRC_ALGORITM_H_
#define SRC_ALGORITM_H_

#include "stack.h"

typedef struct {
    char op;
    int vajn;
} Operator;

Operator add_operator(const char op);
char *infix_to_algoritm(const char *str);
double calc_algoritm(const char *str, const double x);

#endif  // SRC_ALGORITM_H_
