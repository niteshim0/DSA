class TrieNode {
public:
    TrieNode* children[10]; 
    TrieNode() {
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private: 
    TrieNode* root;
public: 
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& key) {
        TrieNode* curr = root;
        for (char c : key) {
            int index = c - '0';
            if (!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
    }

    int findLongestCommonPrefix(const string& key) {
        TrieNode* curr = root;
        int prefixLength = 0;
        for (char c : key) {
            int index = c - '0';
            if (curr->children[index]) {
                prefixLength++;
                curr = curr->children[index];
            } else {
                break;
            }
            
        }
        return prefixLength;
    }
};

class Solution {
private:
    Trie trie;
public:
    int longestCommonPrefix(vector<int>& arr1, const vector<int>& arr2) {
        int ans = 0;
        for(const int& x : arr2){
            trie.insert(to_string(x));
        }
        for(const int& x : arr1){
            ans = max(ans, trie.findLongestCommonPrefix(to_string(x)));
        }
        return ans;
    }
};