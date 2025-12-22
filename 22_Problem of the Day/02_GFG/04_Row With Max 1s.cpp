// https://www.geeksfohttps://www.geeksforgeeks.org/problems/row-with-max-1s0023/1rgeeks.org/problems/row-with-max-1s0023/1
// 22 Dec , 25 (National Mathematics Day)

// Approach I : Binary Search on each array
class Solution {
  public:
    int firstOccurence(vector<int>& nums){
        int n = nums.size();
        int start = 0;
        int end   = n - 1;
        
        int ans = -1;
        
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid] == 1){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        
        return ans == -1 ? 0 : n-ans;
        
        
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        
        int maxi = INT_MIN;
        int row = -1;
        int ansRow = -1;
        for(auto& nums : arr){
            row++;
            int need = firstOccurence(nums);
            if(need>maxi){
                maxi = need;
                ansRow = row;
            }
        }
        
        return ansRow;
        
    }
};

// Time Complexity : O(NlogM)
// Space Complexity : O(1)


// Approach II : 2D Binary Search

class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int m = arr[0].size();
        int n = arr.size();
        
        int row = 0 , col = m-1;
        int maxi = INT_MIN;
        int ans = -1;
        
        while(row<n && col>=0){
            
            if(arr[row][col] == 1){
                int need = m-col;
                if(need>maxi){
                    maxi = need;
                    ans = row;
                }
                col--;
            }else{
                row++;
            }
        }
        
        return ans;
    }
};


// Time Complexity : O(N + M)
// Space Complexity : O(1)