long long binExp(int n,int x,int M){
  long long ans = 1;
  x = x % M;  // Take mod initially to avoid overflow
  while (n > 0) {
      if (n & 1) {
          ans = (ans * x) % M;
          n = n - 1;
      } else {
          x = (x * x) % M;
          n = n / 2;
      }
  }
  return ans;
}
// Time Complexity : O(log2(N))
// Space Complexity : O(1)