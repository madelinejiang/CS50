// Helper functions for music

#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Default octave

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int X=fraction[0] - '0';
    int Y=fraction[2] - '0';
    int Z=(8*X/Y);
    return Z;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
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
                n=-9;
                break;
            case 'D':
                n=-7;
                break;
            case 'E':
                n=-5;
                break;
            case 'F':
                n=-4;
                break;
            case 'G':
                n=-2;
                break;
        }
    n=(n+na+(12*(octave-4)));
    freq=440*pow(2,n/12);
    int ret=round(freq);
    return ret;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(s[0]=='\0')
        return true;
    else
        return false;
}
