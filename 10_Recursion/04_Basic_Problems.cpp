#include<bits/stdc++.h>
using namespace std;
// 1. Print Name N times using Recursion
void print1(int i,int n){
  if(i>n) return;
  cout<<"Nitesh"<<endl;
  print1(i+1,n);
}
// Time Complexity : O(N)
// Auxiliary Stack Space : O(N)

//2. Print Linearly from 1 to N
void print2(int i,int n){
  if(i>n) return;
  cout<<i<<endl;
  print2(i+1,n);
}
// Time Complexity : O(N)
// Auxiliary Stack Space : O(N)

// 3. Print Linearly from N to 1
void print3(int n){
   if(n==0) return;
   cout<<n<<endl;
   print3(n-1); // tail recursion
}
// Time Complexity : O(N)
// Auxiliary Stack Space : O(N)

//4. Print Linearly from 1 to N(backtrack way)
void print4(int i,int n){
  if(i<1) return;
  print4(i-1,n); // non-tail recursion
  cout<<i<<endl;
}
// Time Complexity : O(N)
// Auxiliary Stack Space : O(N)

//5. Print Linearly from N to 1(backtrack way)
void print5(int i,int n){
  if(i>n) return;
  print5(i+1,n); // non-tail recursion
  cout<<i<<endl;
}
// Time Complexity : O(N)
// Auxiliary Stack Space : O(N)
int main(){
 int n;
 cin>>n;
 print1(1,n);
 print2(1,n);
 print3(n);
 print4(n,n);
 print5(n,n);
}