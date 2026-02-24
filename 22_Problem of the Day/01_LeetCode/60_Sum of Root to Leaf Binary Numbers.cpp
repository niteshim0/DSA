// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
// LC 1022 :: Sum of Root to Leaf Binary Numbers
// Concepts :: Binary to Decimal Conversion + Recursion + Iterative and Recursive traversal of binary tree


// Approach I : Store Paths → Convert Binary → Sum
// Collect every root-to-leaf path as a vector of bits, then convert each binary vector to decimal and add them.

// A tree path is just a binary number. If we store it fully, we can process it later.

class Solution {
public:
    vector<vector<int>> all;
    vector<int> path;

    void dfs(TreeNode* node) {
        if(!node) return;

        path.push_back(node->val);

        if(!node->left && !node->right) {
            all.push_back(path);
        } else {
            dfs(node->left);
            dfs(node->right);
        }

        path.pop_back();
    }

    int toDecimal(vector<int>& v) {
        int num = 0;
        for(int bit : v)
            num = num * 2 + bit;
        return num;
    }

    int sumRootToLeaf(TreeNode* root) {
        dfs(root);
        int sum = 0;
        for(auto &v : all)
            sum += toDecimal(v);
        return sum;
    }
};

// Time Complexity : O(N*H)
// Space Complexity : O(N*H)

// Approach II : On-the-Fly Calculation
// Instead of storing paths, build the binary number while traversing.

class Solution {
public:
    int dfs(TreeNode* node, int curr) {
        if(!node) return 0;

        curr = curr * 2 + node->val;

        if(!node->left && !node->right)
            return curr;

        return dfs(node->left, curr) + dfs(node->right, curr);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};

// Time Complexity : O(N)
// Space Complexity : O(H) // Recursion Stack Space

// Approach III : Iterative DFS(Stack)
// Simulate recursion using a stack that stores (node, currentValue).
// Each stack entry represents a partial binary number up to that node.

class Solution {
public:
    bool isLeaf(TreeNode* node){
        return node->left == NULL && node->right == NULL;
    }
    int sumRootToLeaf(TreeNode* root) {

        int sum = 0;
        stack<pair<TreeNode*,int>> st;

        st.push({root,0});

        while(!st.empty()){
            auto [node,curr] = st.top();
            st.pop();

            curr = (curr<<1) | (node->val);

            if(isLeaf(node)) sum+=curr;
            if(node->right) st.push({node->right,curr});
            if(node->left) st.push({node->left,curr});
        }

        return sum;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(H)
