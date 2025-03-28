bool isPossible(vector<int>& arr,int mid,int k){
  int stud = 1;
  int pages = 0;
  for(int &page : arr){
      if(page>mid) return false;
      if(pages+page>mid){
          stud++;
          pages = page;
          if(stud>k) return false;
      }else{
          pages+=page;
      }
  }
  return true;
}
int findPages(vector<int> &arr, int k) {
  // code here
  int ans = -1;
  int start = *max_element(arr.begin(),arr.end());
  int n = arr.size();
  if(k>n) return -1;
  int end = accumulate(arr.begin(),arr.end(),0);
  while(start<=end){
      int mid = start + (end-start)/2;
      if(isPossible(arr,mid,k)){
          ans = mid;
          end = mid-1;
      }else{
          start = mid+1;
      }
  }
  return ans;
}