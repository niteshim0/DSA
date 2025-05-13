#include<bits/stdc++.h>
using namespace std;
int countAllSubsets(int idx,int sum,vector<int>& arr,int k){
  if(sum>k) return 0;
  if(idx == arr.size()){
    if(sum == k){
     return 1;
    }
    return 0;
  }
  sum+=arr[idx];
  int left = countAllSubsets(idx+1,sum,arr,k);
  sum-=arr[idx];
 int right  = countAllSubsets(idx+1,sum,arr,k);
 return left + right;
}
// Time Complexity : O(2^N)
// Space Complexity : O(2^N)
int main(){
  vector<int> arr = {1,2,1};
  cout<<countAllSubsets(0,0,arr,2)<<endl;
}