class Solution {
  public:
    vector<int> getSieve(int N) {
        vector<int> isPrime(N + 1, 1);
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i * i <= N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= N; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        return isPrime;
    }

    int countPrimes(int L, int R) {
        vector<int> prime = getSieve(R);
        int cnt = 0;
        for (int i = 0; i < prime.size(); i++) {
            cnt += prime[i];
            prime[i] = cnt;
        }
        return prime[R] - (L > 0 ? prime[L - 1] : 0);
    }
};
// Time Complexity : O(Nlog(LogN))
// Space Complexity : O(1)