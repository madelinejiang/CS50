#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do
    {

      height=get_int("Height? (must be <23):");

    }
    while (height>23||height<=0);



   for ( int h=0; h< height; h++)//for h times
   {

     for (int i=0; i< height+1; i++)
     {
        if ( i < height-1-h ) printf(" ");
        else printf("#");
     }

     printf("\n");

   }

}