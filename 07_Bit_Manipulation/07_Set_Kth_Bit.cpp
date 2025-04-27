class Solution {
  public:
    int setKthBit(int n, int k) {
        // Code here
        int setter = 1<<k;
        n = n|setter;
        return n;
    }
};