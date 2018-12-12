"""
Alice and Bob are playing the game of Nim.

The game of Nim is played as follows:

    1) n heaps are given containing varying number of stones.
    2) The two players take alternate turns in removing one or more number of stones from a heap.
    3) The last player to remove the last set of stones win.

Given the configuration of heaps at any instant of game help Bob in counting the different moves he can make in one step , so that he finally wins the game.

Input Format:
  First line contain number of testcases t.
  Each testcase consists of two lines:
    The first line contains the number of heaps n.
    The second line contains n separate integers , each denoting no. of stones in the ith pile.

Constraints:
    1<= t <=100
    1<= n <=1000000
    1<= number_of_stones_in_a_heap <= 1000000

Output Format:
  Print the no. of different moves that Bob can make for each testcase.
 
 """
 for t in range(int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    x = 0
    for i in arr:
        x = x^i
    cnt = 0
    for i in arr:
        if (i ^ x) < i:
            cnt += 1
    print(cnt) 
