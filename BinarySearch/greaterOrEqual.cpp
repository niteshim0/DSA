int greaterOrEqual(vector<int>&arr,int target,int s,int e){
    int start = s;
    int end = e;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]>target){
            end = mid - 1;
        }else if(arr[mid]<target){
            start = mid + 1;
        }else{
            return mid;
        }
    }
    return start;
}