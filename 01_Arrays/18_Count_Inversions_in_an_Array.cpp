class Solution {
  public:
    // Function to count inversions in the array.
    int merge(vector<int>&arr,int start,int mid,int end){
        int cnt = 0;
        int left = start;
        int right = mid+1;
        vector<int> temp;
        while(left<=mid && right<=end){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                cnt+=(mid-left+1);
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
        return cnt;
    }
    int mergeSort(vector<int>& arr,int start,int end){
        int cnt = 0;
        if(start>=end) return cnt;
        int mid = start + (end-start)/2;
        cnt+=mergeSort(arr,start,mid);
        cnt+=mergeSort(arr,mid+1,end);
        cnt+=merge(arr,start,mid,end);
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        return mergeSort(arr,0,arr.size()-1);
    }
};

// Time Complexity : O(NlogN)
// Space Complexity : O(N)