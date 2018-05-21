#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do
    {

      height=get_int("Height? (must be <23):");

    }
    while (height>23||height<0);


 for ( int row=1; row<height+1; row++)//how many rows
 {
     for(int column=1; column<2*height+3; column++)//in each column
     {
         if (column<height-row+1||(column>height && column<height+3))
         {
             printf(" ");

         }

         else if (column<height+1||column>2*height+2-row)
         {
             printf("%i", column);
         }
     }
   printf("\n"); }

}
