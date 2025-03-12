// https://leetcode.com/problems/move-zeroes/description/

/*1.Brute Force : -Store all the non-zero element in an temp array.
                  - Fill the start of original array with non-zero elements from temp array.
                  - Fill the remaining places with zero.*/

void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]!=0){
                temp.push_back(nums[i]);
            }
        }
        int i = 0;
        int m = temp.size();
        for(;i<m;i++){
          nums[i] = temp[i];
        }
        for(;i<n;i++){
            nums[i] = 0;
        }
}
//Time Complexity : O(2N)
//Space Complexity :O(#Non-Zero Elements)

/*Optimal Approach : - Use the two pointer concept.
                     - Iterate the array if non-zero element found.
                     - Swap with first pointer.
                     - In the process all non-zero element comes in starting and all the zeroes get right behind all the non-zero elements.
                     */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]!=0){
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                j++;
            }
        }
    }
};