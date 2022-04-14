// Copyright 2022 louisemi
#include <stdio.h>
int find_max(int first, int second, int third);
int find_min(int first, int second, int third);
int find_average(int first, int second, int third);

int main() {
    int input_number = 0;
    scanf("%d", &input_number);
    // 873 / 100 = 8 - first number
    int first = input_number / 100; 
    // (873 / 10) % 10 = 7 - second number
    int second = (input_number / 10) % 10;
    // 873 % 10 = 3 - third number
    int third = input_number % 10; 
    // Number is negative and there are no zeros
    if ((input_number < 0) && (first != 0 && second != 0 && third != 0)) {
        first *= -1;
        second *= -1;
        third *= -1;
        printf("Number is negative and there are no zeros\n");
        printf("-%d%d%d", find_max(first, second, third), find_average(first, second, third), find_min(first, second, third));
    }
    // Number is negative and there are any amount of zeros
    else if (input_number < 0 && (first == 0 || second == 0 || third == 0)) {
        printf("first - %d second - %d third - %d\n", first, second, third);
        first *= -1;
        second *= -1;
        third *= -1;
        printf("Number is negative and there are any amount of zeros\n");
        if (first == 0 && second == 0 && third == 0) {
            printf("-%d%d%d", first, second, third);
            }
        else if (first ==0 && second == 0) {
            printf("-%d%d%d", first, second, third);
            }
        else if (first == 0 && third == 0) {
            printf("-%d%d%d", first, second, third);
            }
        else if (first == 0) {
            printf("-%d%d%d", first, find_max(first, second, third), find_min(first, second, third) + 1);
            }
        else if (second == 0) {
            printf("-%d%d%d", second, find_max(first, second, third), find_min(first, second, third) + 1);
            }
        else if (third == 0) {
            printf("-%d%d%d", third, find_max(first, second, third), find_min(first, second, third) + 1);
            }
    }
    // Number is positive and there are no zeros
    else if (input_number > 0 && (first != 0 && second != 0 && third != 0)) {
        printf("Number is positive and there are no zeros\n");
        printf("%d%d%d", find_max(first, second, third), find_average(first, second, third), find_min(first, second, third));
    }
    // Number is positive and there are any amount of zeros
    else if (input_number > 0 && (first == 0 || second == 0 || third == 0)) {
        printf("Number is positive and there are any amount of zeros");
        if (first == 0) {
            printf("%d%d%d", first, find_max(first, second, third), find_min(first, second, third));
            }
        else if (second == 0) {
            printf("%d%d%d", second, find_max(first, second, third), find_min(first, second, third));
            }
        else if (third == 0) {
            printf("%d%d%d", third, find_max(first, second, third), find_min(first, second, third));
            }
    }
    return 0;    
}

int find_max(int first, int second, int third) {
    int max = 0;
    if (first >= second && first >= third) {
            max = first;
    }
    if (second >= first && second >= third) {
        max = second;
    }
    if (third >= first && third >= second) {
        max = third;
    }
    return max;
}

int find_min(int first, int second, int third) {
    int min = 0;
    if (first <= second && first <= third) {
            min = first;
    }
    if (second <= first && second <= third) {
        min = second;
    }
    if (third <= first && third <= second) {
        min = third;
    }
    return min;
}

int find_average(int first, int second, int third) {
    int average = 0;
    if (first <= second && first >= third) {
            average = first;
        }
    if (second <= first && second >= third) {
        average = second;
    }
    if (third <= first && third >= second) {
        average = third;
    }
    if (first >= second && first <= third) {
        average = first;
    }
    if (second >= first && second <= third) {
        average = second;
    }
    if (third >= first && third <= second) {
        average = third;
    }
    return average;
}

/* 
Задание №2
Написать программу, осуществляющую перестановку крайних цифр в целом трехзначном числе. 
Целое трёхзначное число задаётся на стандартном потоке stdin, результат перестановки выводить 
в виде трёхзначного числа с учётом ведущих нулей на стандартный поток вывода stdout. 
В конце ответа не должно быть переноса.
вход: 159 результат: 951
вход: 120 результат: 021
вход: -123 результат: -321
*/

/*
+ 1. Take input
+ 2. Find first, second and third numbers
+ (Should implement it in output) 3. Work around negative number and substraction sign
4. Create if/else cases to sort numbers in 0987654321 order
5. Output result
6. Cpplint check
7. Check for memory leaks
*/
