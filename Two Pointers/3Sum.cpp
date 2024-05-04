class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Optimized Approach
        //Time Complexity::O(NLogN)+)(N*N)
        //Space Complexity::O(1)
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i==0||i>0&&nums[i]!=nums[i-1])
            {
                int left = i+1;
                int right = nums.size()-1;
                int target = 0-nums[i];
                while(left<right)
                {
                    if(nums[left]+nums[right]==target)
                    {
                        vector<int> req = {nums[i],nums[left],nums[right]};
                        ans.push_back(req);
                        //we have already dodged the duplicacy at i
                    //we need to dodge the duplicacy at left and right
                    while(left<right&&nums[left]==nums[left+1])
                    {
                        left++;
                    }
                     while(left<right&&nums[right]==nums[right-1])
                    {
                      right--;
                    }
                    left++;
                    right--;
                    }
                    else if(nums[left]+nums[right]>target)
                    {
                        right--;
                    }
                    else{
                        left++;
                    }
                   
                }
            }
        }
        return ans;
        
    }
};