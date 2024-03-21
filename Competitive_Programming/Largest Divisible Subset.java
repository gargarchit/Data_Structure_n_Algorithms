/*Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/
class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        
       
        List<Integer>nu=new ArrayList<>();
        if(nums.length==0)
            return nu;
        
         if(nums.length==1)
         {
             nu.add(nums[0]);
             return nu;
         }
       Arrays.sort(nums);
        int dp[]=new int[nums.length];
        for(int i=0;i<dp.length;i++)
            dp[i]=1;
       
        int p[]=new int[nums.length];
        for(int i=0;i<p.length;i++)
            p[i]=-1;
        for(int i=1;i<nums.length;i++){
            
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0)
                {
                    if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                        p[i]=j;
                    }
                }
                
            }
           
        }
        int min=0;
        int r=0;
        for(int i=0;i<nums.length;i++){
            if(dp[i]>min){
                min=dp[i];
                r=i;
            }
        }
        int pa=p[r];
        nu.add(nums[r]);
        while(pa!=-1){
            nu.add(nums[pa]);
            pa=p[pa];
        }
        Collections.reverse(nu);
       
        return nu;
            
            
       
    }
}
