from cs50 import get_string
def main():
    check=False
    sum=0
    while check==False:
        try:
            a=get_string("Please enter a number: ")
            i=int(a)
            check=True
        except ValueError:
            check=False
    if len(a)!=13 and len(a)!=15 and len(a)!=16:
        print("INVALID\n")
        return
    for x in range(0,len(a)-1,2):
        position=len(a)-x-2
        y=2*int(a[position])
        #print(f"position {position} gives {y}")
        z=y//10 +y%10
        sum+=z
    for x in range(0,len(a),2):
        position=len(a)-x-1
        y=int(a[position])
        #print(f"position {position} gives {y}")
        sum+=y
    #print(sum)
    if sum%10!=0:
        print("INVALID\n")
        return
    start=int(a[0])*10+int(a[1])

    if start==34 or start==37:
        cardid="AMEX"
    elif start>=40 and start<=49:
        cardid="VISA"
    elif start>=51 and start<=55:
        cardid="MASTERCARD"
    else:
        print("INVALID\n")
        return
    print(cardid)

def exponent(base,power):
    result=1;
    for x in range(power):
        result*=base
    return result
if __name__=="__main__":
    main()