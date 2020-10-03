/*Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

 

Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
 

Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
0 <= k <= arr.length
*/


class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        if(arr.length==0)
            return -1;
        HashMap<Integer,Integer>hm=new HashMap<>();
        int size=0;
        for(int i=0;i<arr.length;i++){
            if(!hm.containsKey(arr[i])){
                size++;
            }
            
                hm.put(arr[i],hm.getOrDefault(arr[i],0)+1);
                
        }
      
        List<Map.Entry<Integer,Integer>>li=new LinkedList<>(hm.entrySet());
        Collections.sort(li,(o1,o2)->o1.getValue()-o2.getValue());
        for(Map.Entry<Integer,Integer>i:li){
            if(i.getValue()<=k){
                size--;
            k-=i.getValue();
            }
            else
                break;
                
        }
        return size;
        
    }
}
