class Node
{
    int data;
    Node left, right;

    Node(int item)
    {
        data = item;
        left = right = null;
    }
}
*/
class Solution
{
    //Function to return the level order traversal of a tree.
    static ArrayList <Integer> levelOrder(Node root) 
    {
        // Your code here
        ArrayList<Integer> ans = new ArrayList<>();
        if(root == null) return ans;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int levelSize = q.size();
            for(int i = 0;i<levelSize;i++){
                Node node  = q.peek();q.poll();
                ans.add(node.data);
                if(node.left != null) q.add(node.left);
                if(node.right!= null) q.add(node.right);
            }
        }
        return ans;
    }
}