#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long cc_number;
    cc_number=get_long_long("cc#:");
   //last number
   printf("%ld\n",cc_number % 10);
    //2nd to last number
    printf("%ld\n", cc_number/10 % 10);
}