// Generate Permutations of an array
// https://www.geeksforgeeks.org/problems/generate-permutations-of-an-array/1
// Concept :: Recursion + Backtracking

// Approach :: generate all the n! factorial permutation and store them


class Solution {
  public:
    vector<vector<int>> ans;
    void permutationGenerator(vector<int>& arr,unordered_map<int,int>& mp,vector<int>& ds){
        if(ds.size() == arr.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int &x : arr){
            if(mp.find(x) == mp.end()){
                mp[x] = 1;
                ds.push_back(x);
                permutationGenerator(arr,mp,ds);
                mp.erase(x);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        ans.clear();
        unordered_map<int,int> mp;
        vector<int> ds;
        permutationGenerator(arr,mp,ds);
        return ans;
    }
};
// | Type                         | Complexity       |
// | ---------------------------- | ---------------- |
// | **Time**                     | 🕒 **O(n × n!)** |
// | **Space (Auxiliary)**        | 🧠 **O(n)**      |
// | **Space (Including Output)** | 📦 **O(n × n!)** |


