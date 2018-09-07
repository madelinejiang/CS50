/**
 * Copies a BMP piece by piece, just because.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }
    //establish n;

    int n=atoi(argv[1]);
    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    //check to make sure n<=100 and >1
    if(n<1||n>100)
    {
        fclose(inptr);
        fprintf(stderr, "invalid value for n.\n");
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    //establish a new outfile structs
    BITMAPFILEHEADER bfo=bf;
    BITMAPINFOHEADER bio=bi;


    //establish new outfile's dimensions
    bio.biWidth=bi.biWidth*n;//biwidth does not include padding
    bio.biHeight=bi.biHeight*n;

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int newpadding=(4 - (bio.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    bio.biSizeImage=((sizeof(RGBTRIPLE)*bio.biWidth)+newpadding)*abs(bio.biHeight);
    bfo.bfSize=bio.biSizeImage+sizeof(BITMAPINFOHEADER)+sizeof(BITMAPFILEHEADER);


    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&bfo, sizeof(BITMAPFILEHEADER), 1, outptr); //size then number of elements

    // write outfile's BITMAPINFOHEADER
    fwrite(&bio, sizeof(BITMAPINFOHEADER), 1, outptr);



    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
         fseek(inptr, 54+(i*(bi.biWidth*sizeof(RGBTRIPLE)+padding)), SEEK_SET);//inptr: File* to seek from, offset: number of bytes to move cursor, from: SEEK_CUR(current position), SEEK_SET(beginning)
        // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)//per pixel of the input file
            {   // temporary storage
                 RGBTRIPLE triple;
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);//fread(pointer to the struct that will contain your bytes, size to be read, how many elements, source)

               for(int p=0; p<n; p++)
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

            }
            for (int m = 0; m < newpadding; m++)
                {
                    fputc(0x00, outptr);
                 }
             //WRITE CODE TO SEND CURSOR BACK

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
