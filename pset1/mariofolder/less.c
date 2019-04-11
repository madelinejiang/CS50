#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    int space;
    int hashtag;

    do
    {

      height=get_int("Height? (must be <23):");

    }
    while (height>23||height<=0);

 space=height-1;
 hashtag=1;

 for ( int h=0; h< height; h++)//for h times
 {

    for( int i=0; i < space; i++)//type in spaces

    {
           printf(" ");
    }

    for( int j=0; j< hashtag; j++)//type in hashtags
        {
            printf("#");

        }

    space--;
    hashtag++;

    printf("\n");


 }


}
