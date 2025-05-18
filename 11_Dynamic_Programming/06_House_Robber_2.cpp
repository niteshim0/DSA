class Solution {
public:
    int houseRob(vector<long long>& nums) {
        int n = nums.size();
        long long prev1 = nums[0];
        long long prev2 = 0;
        for(int idx = 1;idx<n;idx++){
            long long pick = nums[idx];
            if(idx>1) pick+=prev2;
            long long notPick = prev1;
            long long curr = max(pick,notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        vector<long long> temp1,temp2;
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i = 0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(houseRob(temp1),houseRob(temp2));
    }
};