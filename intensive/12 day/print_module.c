#include <stdio.h>
#include "print_module.h"

char print_char(char ch) {
    return putchar(ch);
}

void print_log(char (*print)(char), char* message) {
    int i = 0;
    while (Log_prefix[i] != '\0') {
        print(Log_prefix[i]);
        i++;
    }
    time_t timer;
    char buffer[20];
    struct tm* tm_info;
    timer = time(NULL);
    tm_info = localtime(&timer);
    strftime(buffer, 20, " %H:%M:%S ", tm_info);
    i = 0;
    while (buffer[i] != '\0') {
        print(buffer[i]);
        i++;
    }
    i = 0;
    while (message[i] != '\0') {
        print(message[i]);
        i++;
    }
}
