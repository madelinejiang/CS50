from enum import Enum
#from pandas import DataFrame #comment out to see matrix

class Operation(Enum):
    """Operations"""

    DELETED = 1
    INSERTED = 2
    SUBSTITUTED = 3

    def __str__(self):
        return str(self.name.lower())

def distances(a, b):

#the following has been heavily influenced by Bernd Klein
#Python Advanced Course Topics Article Levenshtein Distance
#https://www.python-course.eu/levenshtein_distance.php

    i=len(a)+1 #this will be rows
    j=len(b)+1 #this will be columns

    m = [[None] * j for x in range(i)] #columns then rows

    #ensure the first row is x, Operation.Deletion
    for x in range (1,j):
        m[0][x]=(x,Operation(2))

    #ensure the first column is x, Operation, Insertion
    for x in range (1,i):
        m[x][0]=(x,Operation(1))

    #assign 0,None to 0,0
    m[0][0]=(0,None)

    for row in range(1,i):
        for col in range(1,j):
            #check if the letters of a and b match
            if a[row-1] == b[col-1] :
                s=0
            else:
                s=1
            deletion_cost=m[row-1][col][0]+1#deletion
            insertion_cost=m[row][col-1][0]+1#insertion
            substitution_cost=m[row-1][col-1][0]+s#substitution

            if substitution_cost<=deletion_cost and substitution_cost<=insertion_cost:
                cost=substitution_cost
                Op=Operation.SUBSTITUTED
            elif insertion_cost<=deletion_cost and insertion_cost<=substitution_cost:
                cost=insertion_cost
                Op=Operation.INSERTED
            elif deletion_cost<=substitution_cost and deletion_cost<=insertion_cost:
                cost=deletion_cost
                Op=Operation.DELETED
            m[row][col]=(cost,Op)


 #   print(DataFrame(m)) #to see the matrix in a nice format
    # TODO
    return m
