#include "stringi.h"

char *str_push(char *str, const char c) {
    if (str != NULL) {
        char *p = str;
        str = realloc(p, (strlen(str) + 2) * sizeof(char));
        str[strlen(str) + 1] = '\0';
        str[strlen(str)] = c;
    } else {
        str = malloc(2 * sizeof(char));
        str[1] = '\0';
        str[0] = c;
    }
    return str;
}

char *str_free(char *str) {
    if (str)
        free(str);
    return NULL;
}

char *str_input() {
    char *res = NULL, c = getchar();
    while (c != '\0' && c != '\n') {
        res = str_push(res, c);
        c = getchar();
    }
    return res;
}


char *str_del_sp(char *str) {
    const char ops[] = "+_-*/()";
    char *res = NULL;
    int i = 0;
    if (str) {
        while (str[i]) {
            if (str[i] == 's') {
                if (str[i + 1] == 'i' && str[i + 2] == 'n') {
                    res = str_push(res, 's');
                    i += 2;
                } else if (str[i + 1] == 'q' && str[i + 2] == 'r' && str[i + 3] == 't') {
                    res = str_push(res, 'q');
                    i += 3;
                }
            } else if (str[i] == 'c') {
                if (str[i + 1] == 'o' && str[i + 2] == 's') {
                    res = str_push(res, 'c');
                    i += 2;
                } else if (str[i + 1] == 't' && str[i + 2] == 'g') {
                    res = str_push(res, 'g');
                    i += 2;
                }
            } else if (str[i] == 't' && str[i + 1] == 'g') {
                res = str_push(res, 't');
                i += 1;
            } else if (str[i] == 'l' && str[i + 1] == 'n') {
                res = str_push(res, 'l');
                i += 1;
            } else if (str[i] == ' ') {
                i++;
                continue;
            } else if (str[i] == '-' && str[i + 1] != ' ') {
                res = str_push(res, '_');
            } else if ((str[i] >= '0' && str[i] <= '9') || strchr(ops, str[i]) || str[i] == 'x') {
                res = str_push(res, str[i]);
            } else {
                printf("n/a");
                res = str_free(res);
                break;
            }
            i++;
        }
    }
    str_free(str);
    return res;
}

int str_to_int(const char *str) {
    int temp = 0, res = 0, i = 0;
    while (str[i] != '\0') {
        if (str[i] - '0' >= 0 && str[i] - '9' <= 9) {
            temp += ((int) (str[i] - '0')) * pow(10, i);
            i++;
        } else {
            res = -1;
            break;
        }
    }
    i--;
    if (res != -1) {
        for (; i >= 0; i--) {
            res += (temp % 10) * pow(10, i);
            temp /= 10;
        }
    }
    return res;
}
