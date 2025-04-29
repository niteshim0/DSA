class Solution {
  public:
    int XR(int N){
        if(N%4==1) return 1;
        if(N%4==2) return N+1;
        if(N%4==3) return 0;
        if(N%4==0) return N;
    }
    int findXOR(int l, int r) {
        // complete the function here
        return XR(l-1)^XR(r);
    }
};