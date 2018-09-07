#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t BYTE;
#define BLOCKSIZE 512

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage:./recover image\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r"); //open memory card file
    FILE*outptr=NULL;

    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    BYTE BUFFER [BLOCKSIZE];


    int count=0;
    char filename[9];


    while(fread(&BUFFER, BLOCKSIZE, 1, inptr)==1)
    {

      if(BUFFER[0]==0xff&&BUFFER[1]==0xd8&&BUFFER[2]==0xff&&BUFFER[3]>=0xe0&&BUFFER[3]<=0xef)//check start of a new jpeg
        {
            if(outptr!=NULL)//close any files before
                {
                fclose(outptr);
                }

            sprintf(filename, "%03i.jpg",count);
            count++;
            outptr=fopen(filename,"w");
        }
        if(outptr)
        fwrite(&BUFFER, BLOCKSIZE, 1, outptr);//a segmentation fault occurs if you write to NULL

    }
    fclose(outptr);
    fclose(inptr);

    return 0;
}