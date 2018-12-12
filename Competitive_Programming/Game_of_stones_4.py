"""

Alice and Bob are playing an interesting game. They have N piles of stones numbered from 1 to N in front of them. 
The pile contains stones. Both of them play turn wise and optimally with Alice starting first.
In each turn, a player can remove any number of stones from any of the pile which has positive amount of stones left in it.
A player loses when he cannot remove any stone and all piles are already empty.
You are given Q queries. Each query contains two integers integer l and r. 
For each query, your task is to tell winner of the game if it was only played on the piles from range l to r 
(both l and r are inclusive).
Each query is independent from other queries and does not affect them in any way.

Input Format
    The first line of the input contains a single integer N denoting the number of piles.
    The second line contains N space-separated integers where i^th integer denotes the amount of stones in i^th pile.
    The third line contains an integer Q denoting the number of queries. Next Q lines contains two single space separated integers l and r as described in the problem statement.

Constraints
    1<= N <= 5*10^5
    1<= A[i] <= 10^9
    1<= Q <= 2*10^5
    1<= l <= r <= N

Output Format
    Print winner of each query in a separate line. Output "Alice" if Alice wins or "Bob" if Bob wins.

"""

N = int(input())
A = list(map(int, input().split()))
cnt = [0 for x in range(N+1)]
for i in range(1,N+1) :
    cnt[i] = cnt[i-1]^A[i-1]
for Q in range(int(input())) :
    l, r = tuple(map(int, input().split()))
    
    if l == 1 :
        t = cnt[r] 
    else:
        t = cnt[r]^cnt[l-1]
    
    if t == 0:
        print("Bob")
    else:
        print("Alice")
