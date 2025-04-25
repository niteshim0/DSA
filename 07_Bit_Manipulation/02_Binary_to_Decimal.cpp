int binary2Decimal(string x){
  int n = x.size();
  int num = 0;
  int p2 = 1;
  for(int i = n-1;i>=0;i--){
         if(x[i] == '1'){
          num  = num + p2;
         }
         p2 = p2*2;
  }
}
// Time Complexity : O(N)
// Space Complexity : O(1)