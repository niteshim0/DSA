int findCeil(Node* root, int input) {
    // Your code here
    int ceile = -1;
    while(root!=NULL){
        if(root->data == input){
            return input;
        }
        if(input>root->data){
            root = root->right;
        }else{
            ceile = root->data;
            root  = root->left;
        }
    }
    return ceile;
}
// Time Complexity : O(log2(N))
// Space Complexity: O(1)