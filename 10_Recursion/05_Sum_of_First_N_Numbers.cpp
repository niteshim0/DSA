#include<bits/stdc++.h>
using namespace std;

// Parameterized Recursion
void sum1toN(int i,int n){
  if(i<1){
    cout<<n<<endl;
    return ;
  }
  sum1toN(i-1,n+i);
}
int sum1TN(int n){
  if(n==0) return 0;
  return n + f(n-1);
}
int main(){
  int n;
  cin>>n;
  sum1toN(n,0);
  sum1TN(n)
}