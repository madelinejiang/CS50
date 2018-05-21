#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include <math.h>
#include <stdio.h>

int main (void)

{
    string note=get_string();
    char AG=note[0];
    double octave=0;
    double n=0, na=0;
    double freq=0.0;


    if(strlen(note)==3)//no accidental
    {   char accidental=note[1];
        octave=note[2]-'0';
        switch(accidental)
             {
                 case 'b':
               na=-1;
               break;

              case '#':
                na=1;
                break;
            }
    }
    else if(strlen(note)==2)
        { octave=note[1]-'0';
        }

    switch(AG)
        {   case 'A':
                n=0;
                break;
            case 'B':
                n=2;
                break;
            case 'C':
                n=3;
                break;
            case 'D':
                n=5;
                break;
            case 'E':
                n=7;
                break;
            case 'F':
                n=8;
                break;
            case 'G':
                n=10;
                break;
        }
    n=(n+na+(12*(octave-4)));
    freq=440*pow(2,n/12);
    int ret=round(freq);
    return ret;
}