// Minimum Common Value
// https://leetcode.com/problems/minimum-common-value/description/


// Concepts :: Sorting + Two Pointers + Binary Search


//Key Idea : Since both array are sorted , use two pointers to find the first common one.


class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0 , j = 0;

        while(i < n1 && j < n2){

            if(nums1[i] < nums2[j]){
                i++;
            }else if(nums1[i] > nums2[j]){
                j++;
            }else{
                return nums1[i];
            }
        }

        return -1;
    }
};

// Time Complexity : O(N + M)
// Space Complexity : O(1)

// Follow up :: how would you adapt if one array was significantly smaller than the other?

// In that case , for each element of smaller array , use binarySearch on larger array. -> O(Nlog(M)) will outperform O(N+M) here.

class Solution {
public:
    bool binarySearch(int num,vector<int>& nums){
        int n = nums.size();

        int start = 0 , end = n-1;

        while(start <= end){

            int mid = start + (end-start)/2;

            if(nums[mid] > num){
                end = mid - 1;
            }else if(nums[mid] < num){
                start = mid + 1;
            }else{
                return true;
            }
        }

        return false;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        // if one array is significantly smaller than other one.
        int n1 = nums1.size(); // smaller
        int n2 = nums2.size(); // significantly larger than smaller one

        for(int i = 0 ; i < n1 ; i++){

            int x = nums1[i];
            if(binarySearch(x,nums2)){
                return x;
            }
        }

        return -1;
    }
};

// TC : O(NlogM)
// SC : O(1)
