//https://leetcode.com/problems/single-number/

/*1.Brute Force : Use two loops to find the count.
                : If count is one then return it.*/

int singleNumber(vector<int>& nums) {
        for(int &x : nums){
            int need = x;
            int cnt = 0;
            for(int num : nums){
                if(need==num){
                    cnt++;
                }
            }
            if(cnt==1) return need;
        }
        return -1;
}
//Time Complexity : O(N*N)
//Space Complexiyt:O(1)

/*Better Approach : Use HashMap to store the elements and their frequency.
                  : Iterate the hashmap if frequency is 1 then return 1.*/

int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int &x : nums){
            mp[x]++;
        }
        for(auto it : mp){
            if(it.second == 1){
                return it.first;
            }
        }
        return -1;
}
//Time Complexity : O(N)
//Space Complexity : O(N)

/*3.Optimal Approach : Use the XOR concept of a^a==0 and a^0=a
                     : The xor sum of all the elements is our number.*/
int singleNumber(vector<int>& nums) {
  int num = 0;
  for(int &x : nums){
      num^=x;
  }
  return num;
}
//Time Complexity : O(N)
//Space Complexity : O(1)