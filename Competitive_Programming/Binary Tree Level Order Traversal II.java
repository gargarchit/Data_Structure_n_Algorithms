/*Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if(root==null)
            return new ArrayList<>();
        List<List<Integer>> res=new ArrayList<>();
        Queue<TreeNode>qu=new LinkedList<>();
        qu.add(root);
        
        while(!qu.isEmpty()){
            List<Integer>cur=new ArrayList<>();
            
            int size=qu.size();
             
            for(int i=0;i<size;i++){
               
                TreeNode p=qu.remove();
                cur.add(p.val);
                if(p.left!=null)
                    qu.add(p.left);
                if(p.right!=null)
                    qu.add(p.right);
            }
            res.add(0,cur);
        }
        
        return res;
        
    }
}
