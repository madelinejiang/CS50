#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    int k_length;
    string k;


    while (argc!=2)
    {
     printf("Error: ./vigenere string\n");
     return 1;
    }

    k=argv[1];
    k_length = strlen(argv[1]);
    int j=0;

    for(int i=0; i<k_length; i++)
    {
        if(!isalpha(k[i]))
            {
                printf("Error: ./vigenere string\n");
                return 1;
            }
    }


    string s=get_string("plaintext: "); //s=plaintext

    printf("ciphertext: ");


    for (int i=0; i<strlen(s); i++)
        {
            if (isalpha(s[i]))
                {
                    int key;
                    key=tolower(k[j%k_length]) - 'a';

                    if (isupper(s[i]))
                        {

                                 printf("%c",( (s[i]+key) - 65) % 26 + 65);
                        }

                       if (islower(s[i]))
                        {
                                printf("%c", ((s[i]+key) - 97) % 26 + 97);

                        }

                    j++;
                }

            else
                {
                    printf("%c", s[i]);
                }
        }


    printf("\n");
    return 0;
}