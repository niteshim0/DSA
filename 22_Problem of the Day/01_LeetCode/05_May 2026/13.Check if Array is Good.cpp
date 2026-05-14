// LC 2784 . Check if Array is Good
// https://leetcode.com/problems/check-if-array-is-good

// Concepts :: Sorting  + Counting + Hashmap


// Approach I :: Build the Good Array and Compare

class Solution {
public:
    bool isGood(vector<int>& nums) {

        vector<int> ref;
        int maxi = *max_element(nums.begin(),nums.end());

        for(int i = 1 ; i<=maxi; i++){
            ref.push_back(i);
        }

        ref.push_back(maxi);

        sort(nums.begin(),nums.end());

        return nums == ref;

    }
};

// Time Complexity : O(NlogN)
// Space Complexity : O(N)

// Approach II : Sort and compare on the fly

class Solution {
public:
    bool isGood(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return false;
        sort(nums.begin(),nums.end());
        int maxi = nums[n-1];
        if((n-2)>=0 && nums[n-2]!=maxi) return false;

        int cnt = maxi - 1;

        for(int i = n-3 ; i>=0 ; i--){
            
            if(nums[i]!=cnt) return false;
            cnt--;
        }

        return cnt == 0;
    }
};
// Time Complexity : O(NlogN)
// Space Complexity : O(N)



// Approach III : Use Frequency Counters

class Solution {
public:
    bool isGood(vector<int>& nums) {

        int maxi = *max_element(nums.begin(), nums.end());

        unordered_map<int,int> mp;

        for(int num : nums){
            mp[num]++;
        }

        if(mp[maxi] != 2)
            return false;


        for(int i=1;i<maxi;i++){
            if(mp[i] != 1)
                return false;
        }

        return mp.size()==maxi;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)