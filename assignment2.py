from ctypes import sizeof
print (" Hello World Welcome To Sets ") 
A = set([])
no = int(input("Enter the total number in Set A"))
for I in range(no):
    m = int(input("Enter Elements"))
    A.add(m);
B = set([])
no = int(input(" Enter the total number in Set B"))
for i in range(no):
    m = int(input("Enter Elements"))
    B.add(m);
print(" Set A : ",A)
print("Set B : " ,B)
while 1:
    print("\n\n\n *****  MENU ****** \n")
    print("1 : Union")
    print("2 : Intersection")
    print("3 : Set Difference")
    print("4 : Subset")
    print("5 : Is Empty")
    print("6 : Len of A")
    print("7 : Len of B")
    print("8 : size of A And B ")
    print("9 : searching ")
    print("10: Add Element ")
    print("11: Remove Element")
    # print("12: isContAins ")
    # print("" \n\n ")
    ch=int(input("\n***** Enter your Choice ****** \n"))
    if ch==1:
        print("\n Union of A And B As",A.union(B))
    if ch==2:
        print(" \n Intersection of A And B",A.intersection(B))
    if ch==3:
        print("\n Set difference A-B As",A-B)
    if ch==4:
        if A.issubset(B):
            print("\nIs subset")
        else:
            print("\n not A subset")
    if ch==5:
        if len(A)==0:
            print("\n Set A is Empty")
        else:
            print("\n Set A is not empty")
    if ch==6:
        print("Len A=",len(A))
    if ch==7:
        print("Len B=",len(B))
    if ch== 8 :
        print("\n size of A is :",sizeof(A)) 
        print("\n size of A is :",sizeof(B)) 
    if ch== 9 :
        num = int(input(" \n Enter Element to be searched "))
        if num in A :
            print(" \n Number is Found In Set A  ")
        elif num in B:
            print(" \n Number Is Found In Set B  ")
        else :
            print("\n\n Sorry ! Number not Found ")
    if ch==10 :
        Ad = int(input(" Enter Number To Be Added In Set  A "))
        A.add(Ad)
        print(" \n numBer Added In Set A ")
        print("\n  UpdAted Set :  ",A)
    if ch==11 :
        rm = int(input(" Enter Number To Delete "))
        A.remove(rm)
        print("\n  Number Removed ")
        print(" \n  updated Set  " , A)
"""Sets are a type of abstract data type that allows you to store a list of non-repeated values. Their 
name derives from the mathematical concept of finite sets. 
Unlike an array, sets are unordered and unindexed. You can think about sets as a room full of 
people you know. They can move around the room, changing order, without altering the set of 
people in that room. Plus, there are no duplicate people (unless you know someone who has 
cloned themselves). These are the two properties of a set: the data is unordered and it is not 
duplicated. 
Sets have the most impact in mathematical set theory. These theories are used in many kinds of 
proofs, structures, and abstract algebra. Creating relations from different sets and codomains are 
also an important applications of sets. 
In computer science, set theory is useful if you need to collect data and do not care about their 
multiplcity or their order. As we've seen on this page, hash tables and sets are very related. In 
databases, especially for relational databases, sets are very useful. There are many commands 
that finds unions, intersections, and differences of different tables and sets of data. 
"""