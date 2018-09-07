// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int LENGTH=45;
int HASHTABLESIZE=3;
struct hash *hashTable=NULL;
int totalwords=0;

typedef struct node {
        int key;
        char word[45];
        struct node *next;
  } node;


 typedef struct hash {
        struct node *head;
  }hash;

struct  node * createNode(int key, char *word) {
        node *newnode;
        newnode = malloc(sizeof(node));
        newnode->key = key;
        strcpy(newnode->word, word);
        newnode->next = NULL;
        printf("%s allocated to %p\n", word,newnode);
        return newnode;
  }

int hashIndexer(char*word){
    int hash = 0;
    for (int i=0, n=strlen(word); i<n; i++){
        hash = (hash << 2) ^ tolower(word[i]);
    }
    return hash % HASHTABLESIZE;
    }

  void insertToHash(int key,  char *word) {
        int hashIndex = key;
        node *newnode =  createNode(key, word);
        /* head of list for the bucket with index "hashIndex" */
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                printf("There was not a hashtable head before at index %d. Allocation to head %p newnode%p\n",key,hashTable[hashIndex].head,newnode);
                return;
        }
        /* adding new node to the list */
        newnode->next = (hashTable[hashIndex].head);
        /*
         * update the head of the list and no of
         * nodes in the current bucket
         */
        hashTable[hashIndex].head = newnode;

         printf("There was a hashtable head before at index %d. Allocation to head %p newnode%p\n",key,hashTable[hashIndex].head,newnode);
        return;
  }


// Loads dictionary into memory, returning true if successful else false
bool load()
{

        int key;
        char word[45];
        /* create hash table with "n" no of buckets */
         hashTable = calloc(HASHTABLESIZE,sizeof (hash));//8*size of hashtable bytes

        //load function begins
        FILE *fp=fopen("debuggingdict","r");
        if(!fp){
            printf("file does not exits");
         //   free(hashTable);
            return false;}

       while(fgets(word,LENGTH,fp)!=NULL){
           printf("string length fromt fgets is=%lu\n",strlen(word));
            word[strlen(word) - 1] = '\0';
            totalwords++;
            key=hashIndexer(word);
             /*inserting new node to hash table */
            insertToHash(key, word);
       }
       //hashTable=realloc(hashTable,totalwords*sizeof(hash)); didn't like realloc
        fclose(fp);

    // TODO
    return true;
}

bool check(const char *wordt)
{   bool flag = false;

    printf("%s\n",wordt);
    printf("%lu\n",strlen(wordt));
    char word[1+strlen(wordt)];

    for (int i=0, n=strlen(wordt); i<n; i++)
    word[i]=tolower(wordt[i]);



        node *myNode=malloc(sizeof(node));
        myNode->next=NULL;

        printf("%s\n", word);
        int hashIndex = hashIndexer(word);
        myNode = hashTable[hashIndex].head;
        if (!myNode) {
                return flag;
        }
        while (myNode != NULL) {
                if (strcmp(myNode->word,word)==0) {
                        flag = true;
                        printf("Word exists");
                        break;
                }
                myNode = myNode->next;
        }
        return flag;
  }

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
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
    // free(hashTable);
        }

    hashTable[i].head=NULL;

    }

    if(howmanyleft==0)
        return true;
    return false;
}


int main(void){
    load();
    //check("cat");
    unload();
    return 0;

}