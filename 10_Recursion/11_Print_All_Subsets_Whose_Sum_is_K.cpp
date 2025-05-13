#include<bits/stdc++.h>
using namespace std;
void printAllSubsets(vector<int>& ds,int idx,int sum,vector<int>& arr,int k){
  if(idx == arr.size()){
    if(sum == k){
    for(auto &el : ds){
      cout<<el<<" ";
    }
    cout<<endl;
  }
    return ;
  }
  ds.push_back(arr[idx]);
  sum+=arr[idx];
  printAllSubsets(ds,idx+1,sum,arr,k);
  ds.pop_back();
  sum-=arr[idx];
  printAllSubsets(ds,idx+1,sum,arr,k);
}
// Time Complexity : O(2^N)
// Space Complexity : O(2^N)
int main(){
  vector<int> arr = {1,2,1};
  vector<int> ds;
  printAllSubsets(ds,0,0,arr,2);
}