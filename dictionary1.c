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

struct  node * createNode( char *word) {
        node *newnode;
        newnode = malloc(sizeof(node));
        if(!newnode){
            unload();
            return false;
        }
        strcpy(newnode->word, word);
        newnode->next = NULL;
        return newnode;
  }

int hashIndexer(char*word){
    unsigned int hash = 0;
    for (int i=0, n=strlen(word); i<n; i++){
        hash = (hash << 2) ^ tolower(word[i]);
    }
    return hash % HASHTABLESIZE;
    }

  void insertToHash(char *word) {
        int hashIndex = hashIndexer(word);
        node *newnode =  createNode(word);
        /* head of list for the bucket with index "hashIndex" */
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                return;
        }
        /* adding new node to the list */
        newnode->next = (hashTable[hashIndex].head);
        /*
         * update the head of the list and no of
         * nodes in the current bucket
         */
        hashTable[hashIndex].head = newnode;
        return;
  }


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

        char word[LENGTH+1];

        /* create hash table with "n" no of buckets */
        hashTable = calloc(HASHTABLESIZE,sizeof(hash));

        //load function begins
        FILE *fp=fopen(dictionary,"r");
        if(!fp){

            //free(hashTable->head);
            return false;}

       while(fgets(word,LENGTH+2,fp)!=NULL){
            word[strlen(word) - 1] = '\0';
            totalwords++;
             /*inserting new node to hash table */
            insertToHash(word);

       }

        fclose(fp);
        /*free(hashTable->head);
        free(hashTable);*/
    // TODO
    return true;
}


bool check(const char *wordt)
{  // printf("wordt to be checked: %s with length of %lu \n",wordt,strlen(wordt));
    bool flag = false;
    char word[LENGTH + 1];

    for (int i=0, n=strlen(wordt); i<n; i++){
        word[i]=tolower(wordt[i]);

    }

    word[strlen(wordt)] = '\0';
    //printf("%s is going to be compared \n",word);

     int hashIndex = hashIndexer(word);


        /*node *myNode=calloc(1,sizeof(node));
                if (!myNode) {
               // free(myNode);
                return flag;
        }*/

        //myNode->next=NULL;

        node* myNode = hashTable[hashIndex].head;


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
        if(hashTable[i].head!=NULL){

            node*ptr=hashTable[i].head;
            while(ptr!=NULL)
            {
                node*next=ptr->next;
                free(ptr);

                ptr=next;
                howmanyleft--;//if totalwords does not become 0 return false

            }

}
    hashTable[i].head=NULL;
}

    if(howmanyleft==0)
        return true;
    return false;
}