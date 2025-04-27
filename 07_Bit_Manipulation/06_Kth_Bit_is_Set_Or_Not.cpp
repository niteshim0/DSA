class Solution {
  public:
    bool checkKthBit(int n, int k) {
        // Your code here
        int checker = 1<<k;
        if(n&checker) return true;
        return false;
    }
};