// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

int totalwords=0;

typedef struct node {
        char word[LENGTH+1];
        struct node *next;
  } node;


node*hashTable[HASHTABLESIZE];


int hashIndexer(char*word){


     unsigned long hash = 5381;

     for (const char* ptr = word; *ptr != '\0'; ptr++)
     {
         hash = ((hash << 5) + hash) + tolower(*ptr);
     }

     return hash % HASHTABLESIZE;
 }

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

        char word[LENGTH+1];

        /* create hash table with "n" no of buckets */
        //load function begins
        FILE *fp=fopen(dictionary,"r");
        if(!fp){

            //free(hashTable->head);
            return false;}

        fseek(fp,0,SEEK_END);
        long length=ftell(fp);
        fseek(fp,0,SEEK_SET);
        char dictionarystr[length+1];
        fread(dictionarystr, sizeof(char),length, fp);
        dictionarystr[length] = '\0';


        char *tokenPtr=strtok(dictionarystr,"\n");

       while(tokenPtr != NULL){
           strcpy(word,tokenPtr);
            word[strlen(word) - 1] = '\0';
            totalwords++;
             /*inserting new node to hash table */

        int hashIndex = hashIndexer(word);

        if (!hashTable[hashIndex]) {
                hashTable[hashIndex] = malloc(sizeof(node));
                    if(!hashTable[hashIndex])
                    {
                        return unload();
                    }
                strcpy(hashTable[hashIndex]->word,word);
                hashTable[hashIndex]->next=NULL;
        }
        else{
        node *newnode =  malloc(sizeof(node));
            if(!newnode){
                return unload();
            }
        strcpy(newnode->word, word);
        newnode->next = NULL;

/* adding new node to the list */
        newnode->next = hashTable[hashIndex];
        /*
         * update the head of the list and no of
         * nodes in the current bucket
         */
        hashTable[hashIndex] = newnode;

       }
       tokenPtr=strtok(NULL,"\n");

}
        fclose(fp);

    return true;
}


bool check(const char *wordt)
{  // printf("wordt to be checked: %s with length of %lu \n",wordt,strlen(wordt));
    bool flag = false;
    char word[LENGTH+1];
    for (int i=0, n=strlen(wordt); i<n; i++){
        word[i]=tolower(wordt[i]);

    }

    word[strlen(wordt)] = '\0';

     int hashIndex = hashIndexer(word);


        /*node *myNode=calloc(1,sizeof(node));
                if (!myNode) {
               // free(myNode);
                return flag;
        }*/

        //myNode->next=NULL;

        node* myNode = hashTable[hashIndex];


        while (myNode != NULL) {
                if (strcmp(myNode->word,word)==0) {
                        flag = true;
                        break;
                }
               myNode=myNode->next;
        }

        return flag;
  }


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return totalwords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{   int howmanyleft=totalwords;
    for(int i=0; i<HASHTABLESIZE; i++){
        if(hashTable[i]!=NULL){

            node*ptr=hashTable[i];
            while(ptr!=NULL)
            {
                node*next=ptr->next;
                free(ptr);

                ptr=next;
                howmanyleft--;//if totalwords does not become 0 return false

            }

}
    hashTable[i]=NULL;
}

    if(howmanyleft==0)
        return true;
    return false;
}