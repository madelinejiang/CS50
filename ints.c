#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("enter in x\n");
    int x=get_int();
    printf("enter in y\n");
    int y=get_int();
    printf("the sum of x and y is %i\n", x+y);
    printf("the difference of x and y is %i\n", x-y);
    printf("the product of x and y is %i\n", x*y);
    printf("the division of x and y is %i\n", x/y);
    printf("the remainder of x and y is %i\n", x%y);
}