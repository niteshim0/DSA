//Union of Arrays with Duplicates
//https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1
//Concepts :: Working of hashset

// Approach :: Insert the element of both array a and b in the set , since set only insert one time any element , so in set element will always be distinct, insert these set elements in ans vector , that we will return.

class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> st;
        for(int& x : a) st.insert(x);
        for(int& x : b) st.insert(x);
        
        vector<int> ans(st.begin(),st.end());
        
        return ans;
    }
};

// Time Complexity : O(M+N)
// Space Complexity : O(no of distinct elements)