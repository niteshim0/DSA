// Count Subarrays with given XOR
// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
// Concepts :: XOR Properties + PrefixCount Approach + HashMap


/*
// Key Idea
--> Use prefix XOR.
--> If two prefixes have XOR values p1 and p2, then the XOR of the subarray between them is p1 ⊕ p2.So to get subarray XOR = k, we need a previous prefix equal to currentPrefix ⊕ k.*/

/*

// Intuition

--> XOR has a very useful property:

  𝐴⊕𝐵 = 𝐶 ⇒ 𝐴 = 𝐵⊕𝐶


While traversing the array:
-> Keep the XOR of elements from start to current index (prefixXOR)
-> For the current position, ask:
“How many earlier prefixes exist such that their XOR with my current prefix gives k?”

That value is prefixXOR ⊕ k
Each such prefix forms a valid subarray ending at the current index.
*/

// Interview Explanation 

/*“I maintain a running prefix XOR.
For every index, I check how many times prefixXOR ^ k has appeared before, because XORing that prefix with the current one gives k.
I store frequencies of all prefix XORs in a hashmap.
This allows me to count all valid subarrays in one pass.”

Why freq[0] = 1?
It handles subarrays starting from index 0.
If prefixXOR == k, then prefixXOR ^ k = 0, and we correctly count that subarray.

Why this works efficiently
Brute force checks all subarrays → O(n²)
Prefix XOR + hashmap avoids rechecking → O(n)
*/

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        
        unordered_map<int,int> freq;
        freq[0] = 1;
        
        int prefixXOR = 0;
        long long cnt = 0;
        
        for(int& el : arr){
            
            prefixXOR^=el;
            int target  = prefixXOR^k;
            
            if(freq.find(target)!=freq.end()){
                cnt+=freq[target];
            }
            
            freq[prefixXOR]++;
        }
        
        return cnt;
    }
};



// Time Complexity: O(n)
// Space Complexity : O(n)