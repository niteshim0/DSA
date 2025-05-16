class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    void solve(int idx,string& s,vector<string>& path,vector<vector<string>>& res){
        if(idx == s.size()){
            res.push_back(path);
            return;
        }
        for(int i = idx;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,path,res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        solve(0,s,path,res);
        return res;
    }
};
// Time and Space Complexity

// ✅ Time Complexity: `O(2ⁿ × n)`
- Up to `2^(n-1)` possible palindromic partitions.
- Each partition can have up to `n` substrings → O(n) work per partition.

// ✅ Space Complexity:
- **O(2ⁿ × n)** → to store the final list of all palindromic partitions.
- **O(n)** → auxiliary space for recursion stack and current path during backtracking.

// Its optimization can be done will do in DP module
