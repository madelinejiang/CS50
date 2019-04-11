from cs50 import get_string
import sys
def main():
    if len(sys.argv) != 2:
        print("Usage: ./vigenere string")
        sys.exit(1)
    k=sys.argv[1]
    if(k.isalpha()==False):
        print("Usage: ./vigenere string")
        sys.exit(1)
    s=get_string("plaintext: ")
    print("ciphertext: ", end="")

    j=0
    for c in s:
        if(c.isalpha()):
            key=ord(k[j%len(k)].lower())-97
            if(c.isupper()):
                d=ord(c)
                output=chr((d-65+key)%26+65)
                j+=1
            elif(c.islower()):
                d=ord(c)
                output=chr((d-97+key)%26+97)
                j+=1
        else:
            output=c
        print(output,end="")
    print("")

if __name__=="__main__":
    main()