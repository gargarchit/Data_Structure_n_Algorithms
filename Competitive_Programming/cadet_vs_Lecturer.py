"""
One day a Lecturer of CSE got angry with a ProjectX member for coming late in project report submission. 
He gave a tough task to the member only after completion of which he will get his report signed. 
The member solved the problem in less than 10 minutes abd walked out with swag ;).
Can you solve this and prove your worth to ProjectX?

"Given a string S consisting of letters 'A' and 'B'. Calculate the minimum number of changes required such that all A's 
are adjacent to each other and all B's are adjacent to each other."

One change is equivalent to swapping two neighbouring letters.

Input Format
    The first line contains t - the number of test cases .
    Each test case consists of a string S consisting of characters 'A' and 'B' only.

Constraints
    1<=t<=10
    1<=|S|<= 10^6

Output Format
    Desired O/p
    
"""

a1 = 0
a2 = 0
for t in range(int(input())):
    ar = list(input())
    
    a1 = 0
    p1 = -1
    p2 = -1
    arr = ar.copy()
    for ch in range(len(arr)):
        if arr[ch]=='A' and p1==p2 :
            p1 = p1 + 1
            p2 = p2 + 1
        if arr[ch] =='B' and p1>=p2 :
            p1 = p1 + 1
        if arr[ch] =='A' and p1!=p2 :
            p1 = p1 + 1
            p2 = p2 + 1
            a1 = a1 + p1-p2
            temp = arr[p1]
            arr[p1] = arr[p2]
            arr[p2] = temp
            
    a2 = 0
    p1 = -1
    p2 = -1
    arr2 = ar.copy()
    for ch in range(len(arr2)):
        if arr2[ch]=='B' and p1==p2 :
            p1 = p1 + 1
            p2 = p2 + 1
        if arr2[ch] =='A' and p1>=p2 :
            p1 = p1 + 1
        if arr2[ch] =='B' and p1!=p2 :
            p1 = p1 + 1
            p2 = p2 + 1
            a2 = a2 + p1-p2
            temp = arr2[p1]
            arr2[p1] = arr2[p2]
            arr2[p2] = temp
    
    print(min(a1,a2))
