#include<bits/stdc++.h>
using namespace std;
int fact(int n){
  if(n==0) return n;
  return n*fact(n-1);
}
// Time Complexity : O(N)
// Space Complexity : O(N)
int main(){
int n;
cin>>n;
cout<<fact(n)<<endl;
}