void prime_factors(vector<int> queries){
  vector<int> spf(1e5+1,0);
  for(int i = 1;i<=1e5;i++){
    spf[i] = i;
  }
  for(int i = 2;i*i<=1e5;i++){
    if(spf[i] == i){
       for(int j = i*i;j<=1e5;j+=i){
          if(spf[j] == j){
            spf[j] = i;
          }
       }
    }
  }
  for(int i = 0;i<queries.size();i++){
    n = queries[i];
    while(n!=1){
      cout<<spf[n]<<" ";
      n = n/spf[n];
    }
  }
}
// Time Complexity : O(Nlog(logN) + q*log2(n))
// Space Complexity :  O(1)