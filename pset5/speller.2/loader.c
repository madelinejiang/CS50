
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

int totalwords=0;

int main(void){

//char word[LENGTH+1];

        /* create hash table with "n" no of buckets */
        //load function begins
        FILE *fp=fopen("small","r");
        if(!fp){
            printf("File does not exist");

            //free(hashTable->head);
            return false;}
        fseek(fp,0,SEEK_END);
        long length=ftell(fp);
        printf("%ld\n",length);

        fseek(fp,0,SEEK_SET);
        char dictionarystr[length+1];

        fread(dictionarystr, sizeof(char),length, fp);
        dictionarystr[length] = '\0';
        fclose(fp);
        printf("%s",dictionarystr);

        char* entity = strtok(dictionarystr, "\n");  //LINE-A, replacing 'buffer' with 'str' the output is correct.


        while (entity != NULL) {
        printf("%s\n", entity);  //this prints strange output as shown below
        entity = strtok(NULL, "\n");
        }

        return 0;
}