#ifndef PRINT_MODULE_H_
#define PRINT_MODULE_H_
#include <stdio.h>
#include <time.h>
#define Module_load_success_message "Output stream module load: success\n"
#define Log_prefix "[LOG]"

void print_log(char (*print) (char), char* message);
char print_char(char ch);

#endif // PRINT_MODULE_H_