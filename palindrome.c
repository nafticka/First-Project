#include <stdio.h>
#include <stdlib.h>

int pow_func(int base, int exp) {
  int power = 1;
  for (int i = 0; i < exp; i++) {
    power *= base;
  }
  return power;
}

int main(int argc, int *argv[]) {
  int number;
  scanf("%d", &number);

  if (number < 0) {
    printf("false\n");
  } else if (number == 0) {
    printf("true\n");
  } else {
    int temp_number, length;
    temp_number = number;
    length = 0;

    while (temp_number > 0) {
      length++;
      temp_number /= 10;
    }

    int rev_number = 0;
    temp_number = number;

    for (int i = 0; i < length; i++) {
      rev_number += (temp_number / pow_func(10, length - i - 1) * pow_func(10, i));
      temp_number %= pow_func(10, length - i - 1);
    }

    if (number == rev_number) {
      printf("true\n");
    } else {
      printf("false\n");
    }
  }
  return 0;
}