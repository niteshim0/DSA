class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        Node* node = root;
        int flor = -1;
        while(node!=NULL){
            if(node->data == x) return x;
            
            if(x>node->data){
                flor = node->data;
                node = node->right;
            }else{
                node = node->left;
            }
        }
        return flor;
    }
};
// Time Complexity : O(log2(N))
// Space Complexity: O(1)