//Soution1 )) Hashing
int majorityElement(vector<int>& nums) {
       unordered_map<int,int> freq;
       int n = nums.size();
       for(int &x : nums){
           freq[x]++;
           if(freq[x]>n/2) return x;
       }
       return -1;
}

//Soution 2)) Sorting
int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
}


//Booyer-Moore Merge Voting Algorithm
int majorityElement(vector<int>& nums) {
       int cnt = 0;
       int ans = 0;
       for(int &x : nums){
           if(cnt == 0){
               cnt = 1;
               ans = x;
           }else{
               if(ans == x){
                   cnt+=1;
               }else{
                   cnt-=1;
               }
           }
       }
       return ans;
}