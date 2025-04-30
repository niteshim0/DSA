#include<bits/stdc++.h>
using namespace std;
int countDigits(int n){
  int temp = n;
  int cnt = 0;
  while(temp>0){
    cnt = cnt+1;
    temp/=10;
  }
  return cnt;
}

int countDigits(int n){
  return log10(n) + 1;
}