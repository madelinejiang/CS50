#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float userinput;
    int changepennies;
    int c=0;

        do
            {

          userinput=get_float("Change owed:\n");

            }
        while (userinput<0);

    //convert userinput into pennies

    changepennies=round(100*userinput);


    while (changepennies>=25)
        {
            c++;
            changepennies=changepennies-25;
        }
    while(changepennies>=10)
        {
            c++;
            changepennies=changepennies-10;

        }
    while( changepennies>=5)
        {
             c++;
            changepennies=changepennies-5;

        }

    while (changepennies>0)
        {
             c++;
            changepennies=changepennies-1;
        }

printf("%d\n", c);
}