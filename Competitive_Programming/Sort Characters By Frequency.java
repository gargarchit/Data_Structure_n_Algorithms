
/*Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/
class Solution {
    public String frequencySort(String s) {
        if(s.isEmpty())
            return ""; 
        HashMap<Character,Integer>hm=new HashMap<>();
        char str[]=s.toCharArray();
        for(Character i:str){
            if(!hm.containsKey(i))
                hm.put(i,1);
            else
                hm.put(i,hm.get(i)+1);
        }
        PriorityQueue<Character>maxheap=new PriorityQueue<>((o1,o2)->hm.get(o2)-hm.get(o1));
        for(Character c:hm.keySet()){
           
                  maxheap.add(c);
        }
      StringBuilder res = new StringBuilder();
        for(int i = maxheap.size()-1; i >= 0 ; i--){
            char ch = maxheap.poll();
            int c = hm.get(ch);
            while(c != 0){
                res.append(ch);
                c--;
            }
        }
        return res.toString();
        
    }
}
