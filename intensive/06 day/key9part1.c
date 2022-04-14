// Copyright louisemi
#include <stdio.h>
#define NMAX 10
int input(int *buffer, int *length);
void output(int number, int *numbers, int count);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);
int main() {
    int length, data[NMAX];
    int numbers[NMAX];
    if (input(data, &length) == 1) {
    int number = sum_numbers(data, length);
    find_numbers(data, length, number, numbers);
    int count = find_numbers(data, length, number, numbers);
    output(number, numbers, count);
} else {
    printf("n/a\n");
}
    return 0;
}
int input(int *buffer, int *length) {
	if (scanf("%d", length) == 1 && *length < NMAX && *length > 0) {
		for (int *p = buffer; p - buffer < *length; p++) {
			if (scanf("%d", p) == 1) 
			return 1;
				}
}
return 1;
}
int sum_numbers(int *buffer, int length)
{
    
	int sum = 0;
	
	for (int i = 0; i < length; i++)
	{ 
		if (buffer[i] % 2 == 0)
		{
			sum = sum + buffer[i];
		}
	}
	return sum;
}
void output (int number, int *numbers, int count) {
    printf("%d\n", number);
  for (int i = 0; i < count ; i++) {
      printf("%d ", numbers[i]);
  }
}
int find_numbers(int* buffer, int length, int number, int* numbers) {
   int count = 0;
for (int i = 0; i < length; i++) {
    if (buffer[i] != 0 && number % buffer[i] == 0) {
        numbers[count] = buffer[i];
        count++;
    }
}

return count;
}
