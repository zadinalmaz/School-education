#ifndef SRC_STRINGI_H_
#define SRC_STRINGI_H_

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

char *str_input();
char *str_del_sp(char *str);
char *str_push(char *str, const char c);
int str_to_int(const char *str);
char *str_free(char *str);

#endif  // SRC_STRINGI_H_
