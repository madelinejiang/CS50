#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>


int main(void) {
    bool check = false;
    string a = NULL;
    string id = NULL;
    do {
      a = get_string("Enter in a number\n");
      for (int i = 0; i < strlen(a); i++) {
        if (!(a[i] > 47 && a[i] < 58))
          check = false;
        else
          check = true;
      }

    } while (check == false);

    if (!(strlen(a) == 13 || strlen(a) == 15 || strlen(a) == 16)) {
      printf("INVALID\n");
      return 0;
    }

    int sum = 0;

    for (int i = 1; i < strlen(a); i += 2) {
      int position = strlen(a) - i - 1;
      int x = a[position] - '0';
      int y = 2 * x;
      int z = y / 10 + y % 10;
      sum += z;
    }

    for (int i = 1; i <= strlen(a); i += 2) {
      int position = strlen(a) - i;
      int x = a[position] - '0';
      sum += x;
    }

    if (sum % 10 != 0) {
      printf("INVALID\n");
      return 0;
    }
    int start = (a[0] - '0') * 10 + (a[1] - '0');
    if (start == 34 || start == 37) {
      id = "AMEX";
    } else if (start >= 40 && start <= 49) {
      id = "VISA";
    } else if (start >= 51 && start <= 55) {
      id = "MASTERCARD";
    } else {
      printf("INVALID\n");
      return 0;
    }
    printf("%s\n", id);

    return 0;
}