class Solution {
  public:
      bool lemonadeChange(vector<int>& bills) {
          int cntFive = 0;
          int cntTen = 0;
          for(int &bill : bills){
              if(bill == 5){
                  cntFive++;
              }else if(bill == 10){
                  if(cntFive<=0) return false;
                  cntFive--;
                  cntTen++;
              }else if(bill == 20){
                  if(cntFive>=1 && cntTen>=1){
                      cntFive--;
                      cntTen--;
                  }else if(cntFive>=3){
                      cntFive-=3;
                  }else{
                      return false;
                  }
              }
          }
          return true;
      }
  };
// Time Complexity : O(N)
// Space Compleixty : O(1)