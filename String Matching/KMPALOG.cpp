#include<bits/stdc++.h>
using namespace std;
vector<int> prefixTable(const string& pattern){
  int m   = pattern.size();
  vector<int> LPS(m,0);
  int i = 1,j = 0;
  while(i<m){
    if(pattern[i] == pattern[j]){
        LPS[i] = j + 1;
        i++;
        j++;
    }else if(j>0){
      j = LPS[j-1];
    }else{
      LPS[i] = 0;
      i++;
    }
  }
  return LPS;
}
vector<int> KMPAlgo(const string& text,const string& pattern){
  vector<int> LPS = prefixTable(pattern);
  vector<int> ans;
  int i = 0;
  int j = 0;
  int n = text.size();
  int m = pattern.size();
  while(i<n){
    if(text[i] == pattern[j]){
      if(j == m-1){
        ans.push_back(i-j);
        j = 0;
      }else{
        i++;
        j++;
      }
    }else if(j>0){
      j  = LPS[j-1];
    }else{
      i++;
    }
  }
  return ans;
}
int main(){
   string text = "isawsquirrelnearmysquirrelhouseohmy";
   string a = "my";
   string b = "squirrel";
   vector<int> va = KMPAlgo(text,a);
   cout<<va.size()<<endl;
   vector<int> vb = KMPAlgo(text,b);
   for(auto & x : va){
    cout<<x<<" ";
   }
   cout<<endl;
   for(auto & x : vb){
    cout<<x<<" ";
   }
   cout<<endl;
}