// BFS VERSION
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        queue<TreeNode*> q;
        string str = "";
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();q.pop();
            if(node == NULL) str.append("#,");
            else str.append(to_string(node->val)+",");
            if(node!=NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
       return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();q.pop();
            getline(s,str,',');
            if(str == "#") node->left = NULL;
            else {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            getline(s,str,',');
            if(str == "#") node->right = NULL;
            else {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)

// DFS VERSION