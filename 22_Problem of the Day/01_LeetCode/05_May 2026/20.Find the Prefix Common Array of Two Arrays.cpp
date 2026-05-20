// LC 2657. Find the Prefix Common Array of Two Arrays
// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays


// Concepts :: Hashing / Simulation / Maths / Bit Manipulation


// Key Idea :: If elements are common , set size increase by only one , if not then by two , count elements from both the arrays till index i , and then subtract the set size till that index

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        unordered_set<int> st;
        vector<int> ans;

        int n = A.size();

        for(int i = 0 ; i < n ; i++){

            st.insert(A[i]);
            st.insert(B[i]);

            ans.push_back(2 * (i+1) - st.size());
        }

        return ans;

    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)


// Approach II :: Frequency Array Solution

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        int n=A.size();

        vector<int> freq(n+1,0);
        vector<int> ans;

        int common=0;

        for(int i=0;i<n;i++){

            freq[A[i]]++;

            if(freq[A[i]]==2)
                common++;

            freq[B[i]]++;

            if(freq[B[i]]==2)
                common++;

            ans.push_back(common);
        }

        return ans;
    }
};


// Approach III :: Bit Manipulation  , since here n <=50 , its very valid , not for larger nos

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        long long maskA=0;
        long long maskB=0;

        vector<int> ans;

        for(int i=0;i<A.size();i++){

            maskA|=(1LL<<A[i]);
            maskB|=(1LL<<B[i]);

            ans.push_back(
                __builtin_popcountll(maskA&maskB)
            );
        }

        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

