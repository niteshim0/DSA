// Recursive Approach;
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q == NULL){
            return (p == q);
        }

        return p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}
// Time Complexity : O(N)
// Space Complexity : O(N)

// Iterative Approach
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            return p == q;
        }

        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);

        while (!q1.empty() && !q2.empty()) {
            TreeNode* first = q1.front(); q1.pop();
            TreeNode* second = q2.front(); q2.pop();

            if (first->val != second->val) return false;

            // Compare left children
            if ((first->left == nullptr) != (second->left == nullptr)) return false;
            if (first->left) {
                q1.push(first->left);
                q2.push(second->left);
            }

            // Compare right children
            if ((first->right == nullptr) != (second->right == nullptr)) return false;
            if (first->right) {
                q1.push(first->right);
                q2.push(second->right);
            }
        }

        return q1.empty() && q2.empty();
    }
};
// Time Complexity : O(N)
// Space Complexity : O(2*N)