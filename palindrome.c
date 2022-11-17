#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int pow_func(int base, int exp) {
  int power = 1;
  for (int i = 0; i < exp; i++) {
    power *= base;
  }
  return power;
}

bool isPalindrome(int number) {
  if (number < 0) {
    return false;
  } else if (number == 0) {
    return true;
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
      return true;
    } else {
      return false;
    }
  }
}

int main(int argc, int *argv[]) {
  int number;
  scanf("%d", &number);

  if (isPalindrome(number)) {
    printf("%d is a palindrome.", number);
  } else {
    printf("%d is not a palindrome.", number);
  }

  return 0;
}