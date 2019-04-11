from cs50 import get_int
import sys


def main():
    height=0
    while (height<=0 or height>23):
        height=get_int("Height?(must be<23): ")

    for i in range(height):
        for j in range(height-i-1):
            print(" ",end='')
        for k in range(i+1):
            print("#",end='')
        print("")


if __name__=="__main__":
    main()