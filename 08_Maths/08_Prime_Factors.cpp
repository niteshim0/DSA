class Solution {
  public:
    vector<int> AllPrimeFactors(int N) {
        // Code here
        vector<int> ans;
        for(int i = 2;i*i<=N;i++){
            if(N%i == 0){
                ans.push_back(i);
                while(N%i == 0){
                    N/=i;
                }
            }
        }
        if(N!=1) ans.push_back(N);
        return ans;
    }
};
// Time Complexity : O(sqrt(N)*N)
// Space Complexity : O(1)