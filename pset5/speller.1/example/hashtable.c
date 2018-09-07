#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int hash_function(char* key, int size)
{
    // initialize index to 0
    int index = 0;
    int length=0;

    // sum ascii values
    for (int i = 0; key[i] != '\0'; i++)
    {
        indexarr[i]=atoi(toupper(key[i]));
        length++;
    }

    // mod by size to stay w/in bound of table
    return length*indexarr % size;
}

int main(void)
{
    // get hash table size
    printf("Hash table size: ");
    int size = get_int();

    // get key
    printf("Key: ");
    char* key = get_string();

    // calculate and print index
    printf("The string '%s' is mapped to index %i\n", key,
    hash_function(key, size));

    return 0;
}