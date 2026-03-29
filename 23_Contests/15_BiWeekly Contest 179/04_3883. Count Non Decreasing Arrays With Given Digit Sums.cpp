// 3883. Count Non Decreasing Arrays With Given Digit Sums
// 


class Solution {
public:
    const int MOD = 1e9 + 7;
    map<int,vector<int>> mp;

    int sumOfDigits(int n){
        int digitSum = 0;
        while(n != 0){
            digitSum += (n % 10);
            n /= 10;
        }
        return digitSum;
    }

    void preComputation(){
        int n = 5000;
        for(int i = 0; i <= n; i++){
            int digitSum = sumOfDigits(i);
            mp[digitSum].push_back(i);
        }
    }

    int countArrays(vector<int>& digitSum) {
        preComputation();
        int n = digitSum.size();
        
        for(int& x : digitSum){
            if(mp[x].empty()) return 0;
        }

        vector<long long> prev(5001, 0);

        for(int x : mp[digitSum[0]]){
            prev[x] = 1;
        }

        for(int i = 1; i < n; i++){
            vector<long long> prefix(5001, 0);
            prefix[0] = prev[0];

            for(int j = 1; j <= 5000; j++){
                prefix[j] = (prefix[j-1] + prev[j]) % MOD;
            }

            vector<long long> curr(5001, 0);

            for(int x : mp[digitSum[i]]){
                curr[x] = prefix[x];
            }

            prev = curr;
        }

        long long ans = 0;
        for(int i = 0; i <= 5000; i++){
            ans  = (ans + prev[i]) % MOD;
        }
        
        return ans;
    }
};