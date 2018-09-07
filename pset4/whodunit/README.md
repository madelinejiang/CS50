# Questions

## What's `stdint.h`?

## A header file declares a set of integer types with set widths with defined corresponding macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

## Standardization across different machines for memory allocation of integer types. For example, uint8_t causes the allocation of at least 8 bytes for data type uint8_t.


## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

## 1 byte, 4 bytes, 4 bytes, 2 bytes.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

## 42 4d

## What's the difference between `bfSize` and `biSize`?

## bfSize-size of the BMP file
## biSize-the number of bytes required by the structure BITMAPINFORHEADER.

## What does it mean if `biHeight` is negative?

## The origin is in the upper left-hand corner and the file is read top-down.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

## biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

## The files do not exist.

## Why is the third argument to `fread` always `1` in our code?

## The third argument is the maximum number to be read. In our code, we want to only read 1 pixel at a time.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

## Since the size of each scanline must be a multiple of 4 bytes. If the number of pixels isn't a multiple of 4, padding is required.

## What does `fseek` do?

## a file position indicator that advances by a set number of bytes. Can be used to skip .

## What is `SEEK_CUR`?

## current position of the file position indicator
