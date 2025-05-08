#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
void rec(){
  if(cnt==5){
    return; // base condition
  }
  cout<<cnt<<endl;
  cnt++;
  rec();
}
int main(){
  rec();
}