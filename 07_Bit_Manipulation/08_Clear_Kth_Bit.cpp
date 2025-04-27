class Solution {
  public:
    int clearKthBit(int n, int k) {
        // Code here
        int clearer = ~(1<<k);
        n = n&setter;
        return n;
    }
};