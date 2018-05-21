#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int height;
   // int space;
    //int hashtag;

    do
    {

    height=get_int("Height? (must be <23):");

    }
    while (height>23||height<=0);
}