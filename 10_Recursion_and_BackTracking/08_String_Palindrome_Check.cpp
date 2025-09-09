#include<bits/stdc++.h>
using namespace std;
bool palinCheck(string& str,int start,int end){
  if(start>=end) return true;
  return (str[start] == str[end]) && palinCheck(str,start+1,end-1);
}
// Time Complexity : O(N/2)
// Space Complexity : O(N/2)
int main(){
string str = "racecar";
string str2 = "faltu";
cout<<palinCheck(str,0,str.size()-1)<<endl;
cout<<palinCheck(str2,0,str2.size()-1)<<endl;
}