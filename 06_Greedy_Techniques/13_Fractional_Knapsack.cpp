class Solution {
  public:
    static bool cmp(vector<int>& a,vector<int>&b){
        double a1 = (1.0 * a[0]) / a[1];
        double b1 = (1.0 * b[0]) / b[1];
        return a1 > b1;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> items(n,vector<int>(2));
        for(int i = 0;i<n;i++){
            items[i][0] = val[i];
            items[i][1] = wt[i];
        }
        sort(items.begin(),items.end(),cmp);
        
        double res = 0;
        
        for(int i = 0;i<n;i++){
            if(items[i][1]<=capacity){
                res+=items[i][0];
                capacity-=items[i][1];
            }else{
                res+=(1.0*items[i][0]/items[i][1])*capacity;
                break;
            }
        }
        return res;
    }
};
// Time Complexity : O(N + NlogN)
// Space Complexity : O(2*N)