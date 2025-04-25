string onesComplement(int N){
  string res = "";
  while(N){
      if(N%2==1){
          res+='0';
      }else{
          res+='1';
      }
      N = N>>1;
  }
  reverse(res.begin(),res.end());
  return res;
}