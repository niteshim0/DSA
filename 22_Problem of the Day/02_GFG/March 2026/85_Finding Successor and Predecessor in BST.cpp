// https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
// Predecessor and Successor
// Concepts :: Binary Search Tree + Traversals + Binary Search concept 


// Approach :: Just applying the binarySearch Concept to reach to the answer.

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

// Time Complexity : O(2*log(n))
// Space Complexity : O(1)