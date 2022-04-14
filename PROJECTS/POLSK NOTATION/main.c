#include "stringi.h"
#include "stack.h"
#include "graph.h"
#include "algoritm.h"

int main() {
    char *str = str_input();
    str = str_del_sp(str);
    char *res = NULL;
    if (str)
        res = infix_to_algoritm(str);
    if (res)
        print_pole(res, calc_algoritm);
    str_free(res);
    str_free(str);
    return 0;
}
