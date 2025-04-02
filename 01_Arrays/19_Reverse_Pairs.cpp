class Solution {
  public:
      void merge(vector<int>&arr,int start,int mid,int end){
          int left = start;
          int right = mid+1;
          vector<int> temp;
          while(left<=mid && right<=end){
              if(arr[left]<=arr[right]){
                  temp.push_back(arr[left]);
                  left++;
              }else{
                  temp.push_back(arr[right]);
                  right++;
              }
          }
          while(left<=mid){
              temp.push_back(arr[left]);
              left++;
          }
          while(right<=end){
              temp.push_back(arr[right]);
              right++;
          }
          for(int i = start;i<=end;i++){
              arr[i] = temp[i-start];
          }
      }
      int countPairs(vector<int>& arr,int start,int mid,int end){
          int cnt = 0;
          int right = mid+1;
          for(int i = start;i<=mid;i++){
              while(right<=end && arr[i]>2*1ll*arr[right]){
                  right++;
              }
              cnt+=(right-(mid+1));
          }
          return cnt;
      }
      int mergeSort(vector<int>& arr,int start,int end){
          int cnt = 0;
          if(start>=end) return cnt;
          int mid = start + (end-start)/2;
          cnt+=mergeSort(arr,start,mid);
          cnt+=mergeSort(arr,mid+1,end);
          cnt+=countPairs(arr,start,mid,end);
          merge(arr,start,mid,end);
          return cnt;
      }
      int reversePairs(vector<int>& nums) {
         return mergeSort(nums,0,nums.size()-1);
      }
  };

// Time Complexity : O(NlogN)
// Space Complexity : O(N)