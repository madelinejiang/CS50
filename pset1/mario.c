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



 for ( int row=0; row< height; row++)//for h times
 {
    for( int column=0; column< 2*height+2+1; column++)
        {
            if (column<height-row-1)
                {printf(" ");}

            else if(column>=height-row-1 && column<height)
                {printf("#");}

            else if(column>=height+1&&column<height+3)
                {printf(" ");}

            else if (column>= height+3 && column <= height+3+row)
            {printf("#");}
        }


    printf("\n");



}
}