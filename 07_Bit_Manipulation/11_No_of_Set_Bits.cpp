class Solution {
  public:
    int setBits(int n) {
        int temp = n;
        int cnt = 0;
        while(temp!=0){
            if(temp&1) cnt++;
            temp = temp/2;
        }
        return cnt;
    }
};
