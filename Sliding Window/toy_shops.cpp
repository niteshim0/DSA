// I have never thought this can be solved simply using sliding window
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minimumDifference(int N, int M, vector<vector<int>> &toys) {
        vector<pair<int,int>> vp; //Pairs of{Prices,Shops}
        for(int i = 0;i<N;i++){
          for(int &el : toys[i]){
            vp.push_back({el,i});
          }
        }
        sort(vp.begin(),vp.end());
        //using sliding window
        int shops = 0;
        unordered_map<int,int> mp;
        int j = 0;
        int i = 0;
        int ans = INT_MAX;
        while(j<vp.size()){
          int x = vp[j].second;
          mp[x]++;
          if(mp[x] == 1){
            shops++;
          }
          while(i<vp.size() && shops == N){
            int lowestPrice = vp[i].first;
            int highestPrice = vp[j].first;
            int y = vp[i].second;
            ans = min(ans,highestPrice-lowestPrice);
            mp[y]--;
            if(mp[y] == 0){
              shops--;
            }
            i++;
          }
          j++;
        }
        return ans;
    }
};