class Solution {
public:
    vector<int> allTraversals(TreeNode* root) {
        vector<int> preOrder;
        vector<int> inOrder;
        vector<int> postOrder;
        if(root == NULL) return preOrder;

        stack<pair<TreeNode*,int>> st;
        st.push({root,1});
        while(!st.empty()){
            auto [node,num] = st.top(); st.pop();
            if(num == 1){
                preOrder.push_back(node->val);
                num++;
                st.push({node,num});
                if(node->left) st.push({node->left,1});
            }else if(num == 2){
                inOrder.push_back(node->val);
                num++;
                st.push({node,num});
                if(node->right) st.push({node->right,1});
            }else{
                postOrder.push_back(node->val);
            }
        }
        vector<vector<int>> ans = {preOrder,inOrder,postOrder};
        return ans;
    }
};
// Time Complexity : O(3*N)
// Space Complexity : O(4*N)