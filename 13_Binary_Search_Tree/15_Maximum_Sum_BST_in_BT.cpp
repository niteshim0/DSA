class NodeValue {
public:
    int minNode, maxNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution {
public:
    NodeValue maxBSTCalculator(Node* root) {
        if (!root) return NodeValue(INT_MAX, INT_MIN, 0);

        auto left = maxBSTCalculator(root->left);
        auto right = maxBSTCalculator(root->right);

        // Check if current subtree is BST
        if (left.maxNode < root->data && root->data < right.minNode) {
            return NodeValue(
                min(root->data, left.minNode),
                max(root->data, right.maxNode),
                left.maxSize + right.maxSize + 1
            );
        }

        // Not a BST, return invalid range
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    int largestBst(Node *root) {
        return maxBSTCalculator(root).maxSize;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)