class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    vector<int> hash(26,0);
	    int maxi = 0;
	    int unique = 0;
	    for(char &ch : s){
	        if(hash[ch-'a'] == 0){
	            unique++;
	        }
	        hash[ch-'a']++;
	        maxi = max(maxi,hash[ch-'a']);
	    }
	    int first = 0,second = 0,third = 0;
for(auto &x : hash){
  if(x!=0){
    if(x == maxi){
      first++;
    }
    if(x == maxi-1){
      second++;
    }
    if(x == 1){
      third++;
    }
  }
}

if(first == unique || second == unique-1 || ((first==unique-1)&&third==1)){
  return true;
}
return false;
	    
	    if(first == unique || second == unique-1 || ((first==unique-1)&&third==1)){
	        return true;
	    }
	    return false;
	    
	}
};