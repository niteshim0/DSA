// 3857. Minimum Cost to Split into Ones
// https://leetcode.com/problems/minimum-cost-to-split-into-ones/

// Concepts :: Logic Manipulation

// Approach :: Since we have to split number such that their multiplication is minimum and sum is equal to that number . 
// for minimimzing multiplication --> its always be better choice to split it into two 1 + x-1 == x // this is the simple logic
// so simply ans be how many 1 x can contain

class Solution {
public:
    int minCost(int n) {
        int temp = n;
        int ans = 0;
        while(temp!=1){
            temp-=1;
            ans+=temp;
        }

        return ans;
    }
};

// TC : O(N)
// SC : O(1)