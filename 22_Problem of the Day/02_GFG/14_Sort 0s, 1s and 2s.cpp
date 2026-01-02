// Sort 0s, 1s and 2s
// https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

class Solution {
  public:
    
    void sort012(vector<int>& arr) {
        // code here
        // Approach I :: Count and replace
        int zero = 0 , one = 0 , two = 0;
        for(int& num : arr){
            if(num == 0) zero++;
            else if(num == 1) one++;
            else two++;
        }
        
        int k = 0;
        while(zero--) arr[k++] = 0;
        while(one--) arr[k++] = 1;
        while(two--) arr[k++] = 2;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)



class Solution {
  public:
    // Approach II : Dutch National Flag Algorithm
    void sort012(vector<int>& arr) {
        int n = arr.size();
        int start = 0 , mid = 0 , end = n-1;
        while(mid<=end){
            if(nums[mid] == 0){
                swap(nums[mid],nums[start]);
                mid++;
                start++;
            }else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[mid],nums[end]);
                // why here we are not moving mid ?
                // because the number we are swapping with it can be either 0,1 or 2
                // if swapped one is 0 , so it must get chance to be in starting point of array (not moving mid)
                // if swappend one is 2 , it must get chance to be in ending part of arry
                end--;
            }
        }
    }
    // Time Complexity : O(N)
    // Space Complexity : O(1)
};