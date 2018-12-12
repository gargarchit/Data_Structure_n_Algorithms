 """
 Vasu is running up a stone staircase with N stones, and can hop(jump) either 1 step, 2 steps or 3 steps at a time.
 You have to count, how many possible ways Vasu can run up to the stone stairs.

Input Format:
  Input contains integer N that is number of steps

Constraints:
  1<= N <=30

Output Format:
  Output for each integer N the no of possible ways w.
  
  """
  
def hop(N) : 
    if (N == 1 or N == 0) : 
        return 1
    elif (N == 2) : 
        return 2
      
    else : 
        return hop(N - 3) + hop(N - 2) + hop(N - 1)
    
    
N = int(input())
print(hop(N))
    
