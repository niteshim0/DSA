class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* node = root;
        Node* successor = NULL;
        Node* predecessor = NULL;

        while (node) {
            if (key < node->data) {
                successor = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }

        node = root;

        while (node) {
            if (key > node->data) {
                predecessor = node;
                node = node->right;
            } else {
                node = node->left;
            }
        }

        return {predecessor, successor};
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)