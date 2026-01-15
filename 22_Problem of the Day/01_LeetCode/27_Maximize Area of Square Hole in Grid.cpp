// LC 2943 . Maximize Area of Square Hole in Grid
// https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/
// Concept : Sorting
// Approach :: Try to remove as many as continous bars you can remove,to make the maximum area square for both vertical as well as horizontal.
// such that vertical bars and horizontal bars are adjacent to each other.

class Solution {
public:
    int maxConsecutiveLength(vector<int>& nums){
        int maxLen = 1 , currLen = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] == nums[i-1] + 1){
                currLen++;
            }else{
                currLen = 1;
            }
            maxLen = max(maxLen,currLen);
        }
        return maxLen;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        
        int hMax = maxConsecutiveLength(hBars);
        int vMax = maxConsecutiveLength(vBars);

        int squareSideLen = min(hMax,vMax) + 1;

        return squareSideLen*squareSideLen;

    }
};

// Time Complexity : O(hlogh + vlogv) // for sorting purposes + O(h + v)//for finding lenght ~ O(hlogh+vlogv)
// Space Complexity : O(logh + logv)  // for stack space during sorting