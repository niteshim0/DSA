/*Lower Bound : Smallest index such that arr[ind]>=target*/

int lower_bound(vector<int>& arr,int target){
  int start = 0;
  int end = ans = arr.size()-1;
  while(start<=end){
    int mid = start +(end-start)/2;
    if(arr[mid]>=target){
      ans = mid;
      end = mid-1;
    }else{
      start = mid+1;
    }
  }
  return ans;
}

// auto lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();


/*Upper Bound : Smallest index such that arr[ind]>target*/
int upper_bound(vector<int>& arr,int target){
  int n = arr.size();
  int  ans = n;
  int start = 0;
  int end = n-1;
  while(start<=end){
    int mid = start +(end-start)/2;
    if(arr[mid]>target){
      ans = mid;
      end = mid-1;
    }else{
      start = mid+1;
    }
  }
  return ans;
}

//auto upper = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

/*Floor : Largest element(X) in the array such that X <=target*/
int findFloor(vector<int>& arr, int x) {
  int n = arr.size();
  int start = 0;
  int end = n-1;
  int ans = -1; // for handling the duplicate case conditions
  while(start<=end){
      int mid = start  + (end-start)/2;
      if(arr[mid]<=x){
          ans = mid;
          start = mid+1;
      }else{
          end = mid-1;
      }
  }
  return ans;
  
}
/*Ceil  : Smallest element(X) in the array such that X >=target*/
int findCeil(vector<int>& arr, int x) {
  int n = arr.size();
  int start = 0;
  int end = n-1;
  int ans = -1;
  while(start<=end){
      int mid = start +(end-start)/2;
      if(arr[mid]>=x){
          ans = mid;
          end = mid-1;
      }else{
          start = mid+1;
      }
  }
  return ans;
}
