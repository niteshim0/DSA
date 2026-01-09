// https://www.geeksforgeeks.org/problems/subarrays-with-at-most-k-distinct-integers/1
// Subarrays With At Most K Distinct Integers
// Concept :: Sliding Window (Variable Window Size) + map

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        
        int n  = arr.size();
        
        unordered_map<int,int> mp;
        int distinctCnt = 0;
        
        int i = 0 , j = 0 , res = 0;
        
        while(j<n){
            
            mp[arr[j]]++;
            if(mp[arr[j]] == 1) distinctCnt++;
            
            while(distinctCnt>k){
                mp[arr[i]]--;
                if(mp[arr[i]] == 0){
                    distinctCnt--;
                    mp.erase(arr[i]);
                }
                i++;
            }

            res+=(j-i+1);
            j++;
        }
        
        return res;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(k)
-------------------------------------------------------------------------------


// Ordered Map            v/s       Unordered Map                (C++)
--------------------------------------------------------------------------------
/*
Feature                      map                          unordered_map
1.Internal Structure       Red-Black Tree                   Hash Table
                         (Balanced BST)
----------------------------------------------------------------------------------
2.Ordering                 Sorted by key                     No order
----------------------------------------------------------------------------------
3.Time Complexity           O(logn)                          O(1)
  (avg)
----------------------------------------------------------------------------------
4.Time Complexity           O(logn)                          O(n)
  (worst)
-----------------------------------------------------------------------------------
5.Memory Usage               Lower                          Higher
----------------------------------------------------------------------------------
6.Iterator Stability         Stable                   Can be invalidated on rehash
----------------------------------------------------------------------------------
7.Use Case                  Need sorted data                 Need fastest lookup
-----------------------------------------------------------------------------------
*/


/* When to use unordered_map ✅ (most common choice)
----------------------------------------------------
 Use it when:
1.You don’t care about key order
2.You want fast lookup, insert, delete
3.Typical competitive programming / backend logic

📌 Default choice for:

Frequency counting
Hashing problems
Caches
Graph adjacency maps
*/


/*
When to use map ✅
------------------
Use it when:
1. You need sorted keys
2.You need range queries
3.You need lower_bound / upper_bound

📌 Examples:
Sweep line algorithms
Calendar scheduling
Ordered statistics (to some extent)
Problems needing predecessor / successor
*/


/*Interview rule of thumb 🧠

If order matters → map
If order doesn’t matter → unordered_map
90% of the time → unordered_map
Use map only when ordering or range queries are required

Say this in interviews 👇
“I’ll use unordered_map for average O(1) performance unless ordering or range queries are required.”* /




