class Solution {
  public:
    static int cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
        return a.second.second > b.second.second;  // Sort by profit descending
    }
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<pair<int, pair<int, int>>> vp;
        int maxDeadline = -1;
        int n = deadline.size();
        
        for (int i = 0; i < n; i++) {
            vp.push_back({i, {deadline[i], profit[i]}});
            maxDeadline = max(maxDeadline, deadline[i]);
        }
        
        sort(vp.begin(), vp.end(), cmp);
        
        int cnt = 0;
        int cntProfit = 0;
        vector<int> hash(maxDeadline + 1, -1);
        
        for (int i = 0; i < n; i++) {
            for (int j = vp[i].second.first; j >= 1; j--) {
                if (hash[j] == -1) {  
                    cnt++;
                    cntProfit += vp[i].second.second;
                    hash[j] = vp[i].first;
                    break;
                }
            }
        }
        
        return {cnt, cntProfit};
    }
};
// Time Complexity  : O(N*maxDeadline)
// Space Complexity : O(maxDeadline)