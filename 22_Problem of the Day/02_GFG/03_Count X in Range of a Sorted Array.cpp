// Count X in Range of a Sorted Array
// 21 Dec,25
// https://www.geeksforgeeks.org/problems/count-x-in-range-of-a-sorted-array/1

class Solution {
  public:
    int freqCalculator(vector<int>& arr,int start,int end,int& target,int firstIdx){
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(arr[mid] < target){
                start = mid + 1;
            }else if(arr[mid]>target){
                end   = mid - 1;
            }else{
                ans = mid;
                if(firstIdx){
                    end = mid-1;
                }else{
                    start = mid+1;
                }
            }
        }
        return ans;
    }
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans;
        ans.clear();
        for(auto& query : queries){
            int firstOccurrence = freqCalculator(arr,query[0],query[1],query[2],1);
            if(firstOccurrence == -1){
                ans.push_back(0); continue;
            }
            int secondOccurence = freqCalculator(arr,query[0],query[1],query[2],0);
            int need = secondOccurence - firstOccurrence + 1 ;
            ans.push_back(need);
        }
        return ans;
    }
};

// Time Complexity : O(NlogN)
// Space Complexity : O(1)