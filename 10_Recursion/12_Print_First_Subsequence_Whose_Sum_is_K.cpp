#include<bits/stdc++.h>
using namespace std;
bool printAllSubsets(vector<int>& ds,int idx,int sum,vector<int>& arr,int k){
  if(idx == arr.size()){
    if(sum == k){
    for(auto &el : ds){
      cout<<el<<" ";
    }
    return true;
  }
    return false ;
  }
  ds.push_back(arr[idx]);
  sum+=arr[idx];
  if(printAllSubsets(ds,idx+1,sum,arr,k)==true) return true;
  ds.pop_back();
  sum-=arr[idx];
 if(printAllSubsets(ds,idx+1,sum,arr,k) == true) return true;
 return false;
}
// Time Complexity : O(2^N)
// Space Complexity : O(2^N)
int main(){
  vector<int> arr = {1,2,1};
  vector<int> ds;
  printAllSubsets(ds,0,0,arr,2);
}