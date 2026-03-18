// Distribute Candies
// https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1

// Concepts :: Depth First Search + Tree DP + Postorder Traversal 


// Approach I : PostOrder Traversal + DFS

// -> We will process first the child then parent , if it contains more than one candy(extra) , move it to its parent , and similary follows till root , whatever the extra encountered take the sum of them.(thats the answer)

class Solution {
  public:
    int ans = 0;
    int dfs(Node* root)
    {
        if(root == NULL) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        ans+=abs(left) + abs(right);
        return root->data + left + right-1;

    }
    int distCandy(Node* root) {
        // code here
        dfs(root);
        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexilty : O(H)


// Approach II :: Iterative DFS (Postorder Traversal using stack)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        
        int moves = 0;

        stack<pair<TreeNode*,bool>> st;
        st.push({root,false});

        unordered_map<TreeNode*,int> balance;

        while(!st.empty()){

            auto [node,visited] = st.top();

            st.pop();

            if(!node) continue;

            if(visited){
               
               int left = balance[node->left];

               int right = balance[node->right];

               moves += abs(left) + abs(right);

               balance[node] = node->val +  left + right - 1;

            }else{

                st.push({node,true});

                st.push({node->right,false});

                st.push({node->left,false});
            }
        }

        return moves;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)