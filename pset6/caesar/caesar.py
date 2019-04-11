import sys
from cs50 import get_string

def main():


    if len(sys.argv) != 2:
        print("Usage: ./caesar k")
        sys.exit(1)
    k=int(sys.argv[1]) % 26
    s=get_string("plaintext: ")
    print("ciphertext: ",end="")

    for c in s:
        if(c.isupper()):
            d=ord(c)
            output=chr((d-65+k)%26+65)
        elif(c.islower()):
            d=ord(c)
            output=chr((d-97+k)%26+97)
        else:
            output=c
        print(output,end="")
    print("")
if __name__=="__main__":
    main()