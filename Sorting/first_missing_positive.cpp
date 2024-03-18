class Solution {
public:
    void swap(vector<int>&arr,int first,int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
   }
    void cyclicSort(vector<int>&arr){
        int i = 0;
        int n = arr.size();
        while (i < n) {
            int correctIdx = INT_MIN;
            if(arr[i]>0){
                correctIdx = arr[i]-1;
            }
            if (arr[i]>0 && arr[i]<=n && arr[i]!= arr[correctIdx]) {
                swap(arr, i, correctIdx);
            } else {
                i++;
            }
        }
    }
    int firstMissingPositive(vector<int>& nums) {
        cyclicSort(nums);
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]!=(i+1)){
                return i+1;
            }
        }
        return n+1;
    }
};