// Longest Span in two Binary Arrays
// https://www.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays5142/1

// Concepts :: PrefixSum + Longest Difference with Subarray Sum == 0 + Binary Arrays Bounded Range Concept

// Approach I :: Simply use Brute Force


// Approach II :: Prefix Difference + HashMap (Accepted Mostly in Interviews)
// If : prefixSum1[i] - prefixSum2[i] == prefixSum1[j] - prefixSum2[j]
// then subarray (i+1 … j) has equal sum in both arrays.

// Maintain diff = pref1 - pref2
// Store first occurrence of each diff
// Same diff again ⇒ valid span

class Solution {
  public:
    void prefixSumGen(vector<int>& prefixSum, vector<int>& arr) {
        int n = arr.size();
        prefixSum[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }
    }

    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();

        vector<int> prefixSum1(n), prefixSum2(n);
        prefixSumGen(prefixSum1, a1);
        prefixSumGen(prefixSum2, a2);

        unordered_map<int,int> mp;
        mp[0] = -1;

        int maxi = 0;

        for(int i = 0; i < n; i++){
            int diff = prefixSum1[i] - prefixSum2[i]; 

            if(mp.find(diff) != mp.end()){
                maxi = max(maxi, i - mp[diff]);
            } else {
                mp[diff] = i;
            }
        }

        return maxi;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)


// Approach III :: Running Prefix Difference

// Instead of two prefix arrays:
// Keep a running difference
// Same difference seen again ⇒ equal sum span exists (prefixSumDifference on the fly)

class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        
        unordered_map<int,int> mp;
        mp[0] = -1;
        
        int diff = 0;
        int maxi = 0;
        
        for(int i = 0; i < n; i++){
            diff += (a1[i] - a2[i]);
            
            if(mp.count(diff)){
                maxi = max(maxi,i - mp[diff]);
            } else {
                mp[diff] = i;
            }
        }
        
        return maxi;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N) or more truly it can be say as O(1) practically (bounded diff range)

// Case of O(1)

// Q. Why People Say O(1) here ?

// A. For binary arrays (0/1):
//   diff = sum(a1) - sum(a2)
//   At any index i:
//   diff ∈ [-i, +i]
//   So total possible diff values : [-n … +n] → 2n + 1
//   That is bounded and small, independent of input values.
//   Hence : Space does not grow with input variety
//   Considered O(1) auxiliary space in interviews / competitive programming

// Interview-Safe Explanation (Best)

// The algorithm uses a hashmap, so formally space is O(n).
// But since arrays are binary, the prefix difference range is bounded to [-n, n], so the number of stored states is limited and treated as O(1) in practice.

// // 2n+1 , n causes confusion explainataion ?
// The Correct Theory Answer (Very Important)
// In asymptotic analysis:

// Any memory that grows with input size n

// is O(n)

// Since:

// Number of possible diff values = 2n + 1

// ➡ Space grows linearly with n
// ➡ Space Complexity = O(n)

// So mathematically:

// Calling it O(1) is incorrect.

// Then Why Do People Say “O(1)”?

// Because of contextual / practical constraints, not theory.

// In competitive programming & interviews:

// Input is binary (0/1)

// diff is bounded

// No dependence on value magnitude, only count

// So people say:

// “O(1) extra space with respect to value range”

// This is an informal shortcut, not strict Big-O.

// The Right Way to Explain (Interview-Perfect)

// Say this 👇

// Formally, the space complexity is O(n) because the auxiliary array size is 2n+1.
// However, since the array values are binary, the prefix difference is tightly bounded and does not depend on input magnitude, so it’s often treated as O(1) auxiliary space in practice.

// This answer shows:

// You know formal Big-O

// You understand why people misuse it

// You won’t get trapped by theory questions

// Analogy (Very Important Intuition)

// Think of this:

// int freq[1000];

// If 1000 is a fixed constant → O(1)

// If 1000 = 2*n + 1 → O(n)

// Your case is the second one.


// Using vector instead of map

int equalSumSpan(vector<int>& a1, vector<int>& a2) {
    int n = a1.size();
    vector<int> first(2*n + 1, -2);
    
    int diff = 0, ans = 0;
    first[n] = -1;
    
    for(int i = 0; i < n; i++){
        diff += (a1[i] - a2[i]);
        
        if(first[diff + n] != -2)
            ans = max(ans, i - first[diff + n]);
        else
            first[diff + n] = i;
    }
    return ans;
  }

// Time Complexity : O(N)
// Space Complexity : O(1) (Auxiliary space)