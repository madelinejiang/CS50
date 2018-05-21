#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float userinput;
    int changepennies;
    int quarters=0;
    int dimes=0;
    int nickels=0;
    int pennies=0;

        do
            {

          userinput=get_float("Change owed:\n");

            }
        while (userinput<0);

    //convert userinput into pennies

    changepennies=round(100*userinput);

    // while quarters can be used
    while (changepennies>=25)
        {
            quarters=quarters+1;
            changepennies=changepennies-25;
        }
    while(changepennies>=10)
        {
            dimes=dimes+1;
            changepennies=changepennies-10;

        }
    while( changepennies>=5)
        {
            nickels=nickels+1;
            changepennies=changepennies-5;

        }

    while (changepennies>0)
        {
            pennies=pennies+1;
            changepennies=changepennies-1;
        }

printf("%d\n", quarters+dimes+nickels+pennies);
}