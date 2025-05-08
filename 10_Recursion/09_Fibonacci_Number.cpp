#include<bits/stdc++.h>
using namespace std;
int fib(int n){
  if(n<=1) return n;
  return fib(n-1) + fib(n-2);
}
// Time Complexity : O(2^N)
// Space Complexity : O(2^N)

int main(){
int n;
cin>>n;
cout<<fib(n)<<endl;
}