string convert2Binary(int n){
  string res = "";
  while(n){
      char ch = (n%2 + '0');
      res+=ch;
      n = n>>1;
  }
  reverse(res.begin(),res.end());
  return res;
}
// Time Complexity : O(log2N)
// Space Complexity :O(Log2N)