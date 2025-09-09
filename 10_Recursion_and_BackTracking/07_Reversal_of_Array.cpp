#include<bits/stdc++.h>
using namespace std;
void reverse(vector<int>& arr,int start,int end){
  if(start>=end) return;
  int temp = arr[start];
  arr[start] = arr[end];
  arr[end] = temp;
  reverse(arr,start+1,end-1);
}
int main(){
vector<int> v = {5,4,3,2,1};
reverse(v,0,4);
for(int &el : v){
  cout<<el<<" ";
}
cout<<endl;
}