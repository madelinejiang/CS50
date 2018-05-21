#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    int k;
    while (argc!=2)
    {
     printf("Usage: ./caesar k\n");
     return 1;
    }


    k = atoi(argv[1]) % 26;
//printf("%d value of k\n",k);

    string s=get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i=0; i<strlen(s); i++)
    {
        if(isupper(s[i]))
        {

            printf("%c",(s[i]-65+k) % 26 + 65);

        }
        else if(islower(s[i]))
        {
            printf("%c",(s[i]-97+k) % 26 + 97);
        }
        else
        {
            printf("%c", s[i]);
        }

    }
    printf("\n");
    return 0;
}