// 03 . Sort by Set Bit Count
// https://www.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1


// Concepts :: Bucket Sort + Map + Stable Sort


// Approach I : Using hashmap to sort as well as collect those element which have same number of bits in one bucket

class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        
        map<int,vector<int>> mp;
        
        vector<int> ans;
        
        for(int &x : arr){
            
            int setBitCnt  = __builtin_popcount(x);
            mp[setBitCnt].push_back(x);
        }
        
        for(auto it = mp.rbegin() ; it!=mp.rend() ; it++){
            
            for(int &el : it->second){
                ans.push_back(el);
            }
        }
        
        return ans;
        
    }
};

// Time Complexity : O(NlogN)
// Space Complexity : O(N)

// Approach 2 :: Bucket Sort :: Since set bit range is (0,32) , so we can create buckets for that

class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        
        vector<vector<int>> buckets(33);
        
        vector<int> ans;
        ans.reserve(arr.size());
        
        for(int &x : arr){
            
            int setBitCnt  = __builtin_popcount(x);
            buckets[setBitCnt].push_back(x);
        }
        
        for(int i = 32 ; i>=0 ; i--){
            
            for(int &el : buckets[i]){
                ans.push_back(el);
            }
        }
        
        return ans;
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)