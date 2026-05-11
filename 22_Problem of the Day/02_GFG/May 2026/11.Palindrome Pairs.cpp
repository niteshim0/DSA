// 11 . Palindrome Pairs
// https://www.geeksforgeeks.org/problems/palindrome-pairs/1

// Concepts :: Trie + Suffix + Prefix + Hashmap + Rolling Hash + Rabin Karp


// Appraoch I : Brute Force Appraoch
// Checking every pair to be in both ways , is they palindrome

class Solution {
  public:
    bool isPalindrome(string& str){
        
        int n = str.size();
        
        int i = 0 ;
        int j = n - 1;
        
        while(i < j){
            
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    bool palindromePair(vector<string>& arr) {
        
        int n  = arr.size();
        
        for(int i = 0 ; i < n ; i++){
            
            for(int j = i + 1 ; j < n ; j++){
                
                string str1 = arr[i] + arr[j];
                string str2 = arr[j] + arr[i];
                if(isPalindrome(str1)) return true;
                if(isPalindrome(str2)) return true;
            }
        }
        
        return false;
    }
};

// Time Complexity : O(N*N*K)
// Space Complexity : O(K)

// Approach II :: Hashmap + Reversal of String

/*
Main idea:

For every word:

split it into prefix and suffix

--> if prefix is palindrome: search reverse(suffix)
--> if suffix is palindrome: search reverse(prefix)


Intuition

Suppose:

word = "abcd"

Partitions:

"" | "abcd"
"a" | "bcd"
"ab" | "cd"
"abc" | "d"
"abcd" | ""

If left part is palindrome, then we need reverse(right).

If right part is palindrome, then we need reverse(left).
*/

class Solution {
  public:
    bool isPalindrome(string str , int start , int end){
        
        int n = str.size();
        
        int i = start ;
        int j = end;
        
        while(i < j){
            
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    bool palindromePair(vector<string>& arr) {
        
        int n  = arr.size();
        
        unordered_map<string,int> mp;
        
        for(int i = 0 ; i < n ; i++){
            
            mp[arr[i]] = i;
        }
        
        for(int i = 0 ; i < n ; i++){
            
            string str = arr[i];
            int len = str.size();
            
            for(int cut = 0 ; cut <= len ; cut++){
                
                string left = str.substr(0,cut);
                string right = str.substr(cut);
                
                
                // Left Palindrome
                if(isPalindrome(str,0,cut-1)){
                    
                    string revRight = right;
                    reverse(revRight.begin(),revRight.end());
                    
                    if(mp.count(revRight) && mp[revRight]!=i) {
                        return true;
                    }
                }
                
                // Right Palindrome
                
                if(cut!=len && isPalindrome(str,cut,len-1)){
                    
                    string revLeft = left;
                    
                    reverse(revLeft.begin(),revLeft.end());
                    
                    if(mp.count(revLeft) && mp[revLeft]!=i){
                        
                        return true;
                    }
                }
            }
            
        }
        
        return false;
    }
};

// Time Complexity : O(N * K * K)
// Space Complexity : O(N)

// Appraoch III :: Using Trie

class TrieNode {
public:

    TrieNode* child[26];

    int wordIndex;

    vector<int> palindromeIndices;

    TrieNode() {

        wordIndex = -1;

        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
};

class Solution {
public:

    bool isPalindrome(const string& s, int l, int r) {

        while(l < r) {

            if(s[l] != s[r]) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }

    void insert(TrieNode* root, string word, int index) {

        reverse(word.begin(), word.end());

        TrieNode* node = root;

        for(int i = 0; i < word.size(); i++) {

            // remaining substring palindrome
            if(isPalindrome(word, i, word.size() - 1)) {
                node->palindromeIndices.push_back(index);
            }

            int c = word[i] - 'a';

            if(node->child[c] == NULL) {
                node->child[c] = new TrieNode();
            }

            node = node->child[c];
        }

        node->wordIndex = index;

        node->palindromeIndices.push_back(index);
    }

    bool search(TrieNode* root, string word, int index) {

        TrieNode* node = root;

        for(int i = 0; i < word.size(); i++) {

            // case:
            // current trie word ended
            // remaining current word palindrome
            if(node->wordIndex != -1 &&
               node->wordIndex != index &&
               isPalindrome(word, i, word.size() - 1)) {

                return true;
            }

            int c = word[i] - 'a';

            if(node->child[c] == NULL) {
                return false;
            }

            node = node->child[c];
        }

        // exact match
        if(node->wordIndex != -1 &&
           node->wordIndex != index) {

            return true;
        }

        // longer matching words
        for(int idx : node->palindromeIndices) {

            if(idx != index) {
                return true;
            }
        }

        return false;
    }

    bool palindromePair(vector<string>& arr) {

        TrieNode* root = new TrieNode();

        int n = arr.size();

        for(int i = 0; i < n; i++) {
            insert(root, arr[i], i);
        }

        for(int i = 0; i < n; i++) {

            if(search(root, arr[i], i)) {
                return true;
            }
        }

        return false;
    }
};
// Time Complexity : O(N * K^2)