class Solution {
  public:
    bool isPrime(int n) {
        int cnt = 0;
         for(int i = 2;i*i<=n;i++){
            if(n%i==0){
                cnt++;
                if(i!=(n/i)){
                    cnt++;
                }
            }
            if(cnt>=2) return false;
        }
        return true;
    }
    
};