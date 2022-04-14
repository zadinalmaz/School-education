    #include "algoritm.h"

    #include <math.h>

    Operator add_operator(const char op) {
        const char ops[] = "()+-_*^/sctgl";
        const char prios[] = "994423322222";
        Operator res;
        size_t i = 0;
        while (op != ops[i])
            i++;
        res.op = ops[i];
        res.vajn = prios[i] - '0';
        return res;
    }


    char *output_f(char *str, const char op) {
        const char *fs[] = {
            "sin",
            "cos",
            "tg",
            "ctg",
            "ln",
            "sqrt"
        };
        const char f_l[] = "sctgl";
        size_t i = 0;
        while (f_l[i] != op)
            i++;
        for (size_t j = 0; j < strlen(fs[i]); j++)
            str = str_push(str, fs[i][j]);
        return str;
    }

    char *link_arg(char *res, const char *str, size_t *i, const char *args) {
        while (strchr(args, str[*i]) && str[*i]) {
            res = str_push(res, str[*i]);
            ++(*i);
        }
        res = str_push(res, ' ');
        --(*i);
        return res;
    }


    char *link_close_skobka(Stack *s, char *res, const char *fs) {
        Operator o = *((Operator*) del_stack(s));
        while (o.op != '(') {
            res = str_push(res, o.op);
            res = str_push(res, ' ');
            if (!is_stack_empty(s))
                o = *((Operator*) del_stack(s));
            else
                break;
        }
        Operator *top = (Operator*) top_stack(s);
        if (top) {
            if (strchr(fs + 2, top->op)) {
                o = *((Operator*) del_stack(s));
                res = output_f(res, o.op);
                res = str_push(res, ' ');
            }
        }
        return res;
    }

    char *link_operator(Stack *s, char *res, const char *str, const size_t i, const char *fs) {
        Operator *top = (Operator*) top_stack(s);
        Operator c_o = add_operator(str[i]);
        if (top) {
            while ((strchr(fs + 2, top->op) || c_o.vajn >= top->vajn) && !is_stack_empty(s)) {
                Operator o = *((Operator*) del_stack(s));
                if (strchr(fs + 2, o.op))
                    res = output_f(res, o.op);
                else
                    res = str_push(res, o.op);
                res = str_push(res, ' ');
                top = (Operator*) top_stack(s);
                if (!top)
                    break;
            }
        }
        push_stack(s, (void*) &c_o, sizeof(Operator));
        return res;
    }


    char *link_error(char *res) {
        printf("[ERROR] Reading undefined symbol.");
        res = str_free(res);
        return res;
    }

    void link_f(Stack *s, const char *str, const size_t i) {
        Operator o = add_operator(str[i]);
        push_stack(s, (void*) &o, sizeof(Operator));
    }

    char *push_last(Stack *s, char *res, const char *fs) {
        Operator o = *((Operator*) del_stack(s));
        if (strchr(fs + 2, o.op))
            res = output_f(res, o.op);
        else
            res = str_push(res, o.op);
        res = str_push(res, ' ');
        return res;
    }

    char *infix_to_algoritm(const char *str) {
        char *res = NULL;
        const char ops[] = "+-*/";
        const char fs[] = "_(sctgl";
        const char args[] = "0123456789x";
        Stack *s = init_stack();
        size_t i = 0;
        if (str) {
            while (str[i]) {
                if (strchr(args, str[i])) {
                    res = link_arg(res, str, &i, args);
                } else if (strchr(fs, str[i])) {
                    link_f(s, str, i);
                } else if (str[i] == ')') {
                    res = link_close_skobka(s, res, fs);
                } else if (strchr(ops, str[i])) {
                    res = link_operator(s, res, str, i, fs);
                } else {
                    res = link_error(res);
                    break;
                }
                i++;
            }
            while (!is_stack_empty(s) && res)
                res = push_last(s, res, fs);
            if (res)
                res[strlen(res) - 1] = '\0';
        }
        destroy_stack(s);
        return res;
    }

    Stack *calc_arg(Stack *s, const char *str, size_t *i, const double x, const char *args) {
        if (str[*i] == 'x') {
            push_stack(s, (void*) &x, sizeof(double));
        } else {
            char *str_number = NULL;
            while (strchr(args, str[*i]) && str[*i]) {
                str_number = str_push(str_number, str[*i]);
                (*i)++;
            }
            (*i)--;
            double number = (double) str_to_int(str_number);
            str_number = str_free(str_number);
            push_stack(s, (void*) &number, sizeof(double));
        }
        return s;
    }

    Stack *calc_operator(Stack *s, const char *str, const size_t i) {
        double x2 = *((double*) del_stack(s)), x1 = *((double*) del_stack(s));
        double res;
        switch (str[i]) {
            case '+':
                res = x1 + x2;
                break;
            case '-':
                res = x1 - x2;
                break;
            case '/':
                if (x2 == 0) {
                    s = destroy_stack(s);
                } else {
                    res = x1 / x2;
                }
                break;
            case '*':
                res = x1 * x2;
                break;
        }
        if (s)
            push_stack(s, (void*) &res, sizeof(double));
        return s;
    }

    Stack *calc_f(Stack *s, const char *str, size_t *i) {
        double res;
        if (str[*i] == '_') {
            res = *((double*) del_stack(s));
            res *= -1;
        } else {
            (*i)++;
            switch (str[*i]) {
                case 'i':
                    res = *((double*) del_stack(s));
                    res = sin(res);
                    (*i)++;
                    break;
                case 'o':
                    res = *((double*) del_stack(s));
                    res = cos(res);
                    (*i)++;
                    break;
                case 'g':
                    res = *((double*) del_stack(s));
                    res = tan(res);
                    break;
                case 't':
                    res = *((double*) del_stack(s));
                    if (tan(res) == 0) {
                        s = destroy_stack(s);
                    } else {
                        res = (double) 1 / tan(res);
                    }
                    (*i)++;
                    break;
                case 'n':
                    res = *((double*) del_stack(s));
                    if (res == 0) {
                        s = destroy_stack(s);
                    } else {
                        res = log(res);
                    }
                    break;
                case 'q':
                    res = *((double*) del_stack(s));
                    res = sqrt(res);
                    break;
            }
        }
        if (s)
            push_stack(s, (void*) &res, sizeof(double));
        return s;
    }

    double calc_algoritm(const char *str, const double x) {
        double res = 10000;
        const char args[] = "0123456789x";
        const char operators[] = "-+*/";
        const char fs[] = "sctl_";
        size_t i = 0;
        Stack *s = init_stack();
        while (str[i]) {
            if (s) {
                if (strchr(args, str[i])) {
                    s = calc_arg(s, str, &i, x, args);
                } else if (strchr(operators, str[i])) {
                    s = calc_operator(s, str, i);
                } else if (strchr(fs, str[i])) {
                    s = calc_f(s, str, &i);
                }
            }
            i++;
        }
        if (s) {
            res = *((double*) del_stack(s));
            destroy_stack(s);
        }
        return res;
    }
