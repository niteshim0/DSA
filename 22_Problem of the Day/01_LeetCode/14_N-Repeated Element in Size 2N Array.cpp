// 961. N-Repeated Element in Size 2N Array
// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

// Approach I :: Using HashMap or HashSet

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        n/=2;
        for(auto &num : nums){
            mp[num]++;
            if(mp[num] == n) return num;
        }
        return -1;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

// Approach II :: Using a smart logic

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        
        // if an element occurs  n times , and all others are unique
        // then in for subarray of 3 it must occur twice
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i + 1])
                return nums[i];
            
            if(i + 2 < n && nums[i] == nums[i + 2])
                return nums[i];
            if(i + 3 < n && nums[i] == nums[i + 3])
                return nums[i];
        }
        
        return -1; 
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)
