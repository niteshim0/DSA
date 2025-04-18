class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(),bt.end());
        long long waitTime = 0;
        long long sum = 0;
        for(auto &x : bt){
            waitTime+=sum;
            sum+=x;
        }
        int n = bt.size();
        return waitTime/n;
    }
};
// Time Complexity : O(NlogN) + O(N)
// Space Complexity: O(1)