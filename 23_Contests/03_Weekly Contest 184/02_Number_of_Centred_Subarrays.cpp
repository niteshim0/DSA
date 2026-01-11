//https://leetcode.com/problems/number-of-centered-subarrays/description/
// Number of Centred Subarrays
// Do as said 

// During Contest
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int sum;
        for(int i = 0;i<n;i++){
            set<int> s; // can be used unordered set for O(1) avg insertion // one can't do better optimization than this in this particular question.
            sum = 0;
            for(int j = i;j<n;j++){
                s.insert(nums[j]);
                sum+=nums[j];
                if(s.find(sum)!=s.end()) cnt++;
            }
            s.clear(); // its pointless , because after loop for i ends , s destroys itself
        }

        return cnt;
    }
};
// Time Complexity : O(N^2logN)
// Space Complexity : O(N)