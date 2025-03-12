// https://leetcode.com/problems/sort-colors/

/*1.Brute Force Approach : Simply use the sort function.*/
// Time Complexity : O(NlogN

/*2.Better Approach : - Count the no of 0s , 1s , 2s
                      - Simply put them into the array as according to sorting*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cntZero = 0,cntOne = 0 , cntTwo = 0;
        for(int &num : nums){
            if(num == 0) cntZero++;
            else if(num==1) cntOne++;
            else if(num==2) cntTwo++;
        }
        int idx = 0;
        int n = nums.size();
        while(idx<n){
            if(cntZero>0){
                nums[idx++] = 0;
                cntZero--;
            }else if(cntZero==0 && cntOne>0){
                nums[idx++] = 1;
                cntOne--;
            }else if(cntZero==0 && cntOne==0 && cntTwo>0){
                nums[idx++] = 2;
                cntTwo++;
            }
        }
    }
};
//Time Complexity : O(N
//Space Complexity : O(3) (Not an inplace algorithm)

/*3.Optimal Approach : -We will use Dutch National Flag Algorithm.
                       - It contains three pointers , low , mid , high.
                       - with condition [0..low-1]=0
                                        [low,mid-1]=1
                                        [end,n-1]= 2
                       - which makes use to sort only the portion of mid to end which may contain anything 0s , 1s , 2s*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0,mid = 0,high = n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }else if(nums[mid] == 1){
                mid++;
            }else if(nums[mid] == 2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
