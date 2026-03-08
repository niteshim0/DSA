// LC 3862. Find the Smallest Balanced Index
// https://leetcode.com/problems/find-the-smallest-balanced-index/
// Concepts :: Overflow Concept + PrefixSum + PrefixProduct Concept

// Approach :: Calculate the prefixProduct from back leaving that idx.
// while iterating second time , calculate prefixSum and when condition of equal to hits , return that index

class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixProduct(n,0);
        long long prod = 1;
        long long LIMIT = 100000000000000LL;
        
        
        for(int i = n-1;i>=0;i--){
            prefixProduct[i] = prod;
            if(prod > (LIMIT/max(1,nums[i]))){
                prod = LIMIT;
            }else{
                prod*=1ll*nums[i];
            }
        }
        long long sum = 0;
        for(int i = 0;i<n;i++){
             if(sum == prefixProduct[i]) return i;
             sum+=nums[i];
        }
        return -1;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N) 

// Fucked up hard time on this ques , taken nearly  6 attempts to solve this ques because can't able to figure out the overflow part