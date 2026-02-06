// Happiest Triplet
// https://www.geeksforgeeks.org/problems/happiest-triplet2921/1

class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
         sort(a.begin(),a.end());
         sort(b.begin(),b.end());
         sort(c.begin(),c.end());
         int i = 0 , j = 0 , k = 0;
         int minDiff = INT_MAX;
         int n = a.size();
         vector<int> ans(3,-1);
         
         while(i<n && j < n && k <n){
            int maxi = max({a[i],b[j],c[k]});
            int mini = min({a[i],b[j],c[k]});
            int currDiff = maxi - mini;
             if(currDiff<minDiff){
                 minDiff = currDiff;
                 ans[0] = a[i];
                 ans[1] = b[j];
                 ans[2] = c[k];
             }
             if(mini == a[i]) i++;
             else if(mini == b[j]) j++;
             else k++;
         }
         sort(ans.begin(),ans.end(),greater<int>());
         return ans;
    }
};

// Time Complexity : O(NlogN)
// Space Complexity : O(N)