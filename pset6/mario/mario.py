from cs50 import get_int
import sys

def main():
    height=get_int("Height?(must be<23): ")
    while (height<0 or height>23):
        height=get_int("Height?(must be<23): ")

    for i in range(height):
        for j in range(2*height+2):
           if j<(height-i-1):
               print(" ",end='')
           elif(j<height):
               print("#",end='')
           elif(j<height+2):
               print(" ",end='')
           elif(j<i+height+3):
               print("#",end='')

        print("")

if __name__=="__main__":
    main()