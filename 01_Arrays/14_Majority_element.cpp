// https://leetcode.com/problems/majority-element/

/*1.Brute Force Approach : - Take two nested loops.
                           - Count the occurence of each element.
                           - If cnt exceeds > n/2 then return it.*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int &x : nums){
            int num = x;
            int cnt = 0;
            for(int &y : nums){
                if(x==y) cnt++;
            }
            if(cnt > (n/2)) return num;
        }
        return -1;
    }
};
//Time Complexity : O(N*N)
//Space Complexity : O(1

/*2.Better Approach : Use the hashmap to store and count the elements.
                    : if cnt of element exceeds>n/2 return it.*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int &x : nums){
            mp[x]++;
            if(mp[x]>n/2){
                return x;
            }
        }
        return -1;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)

/*3.Optimal Approach : -Booyer Moore Merge Voting Algorithm.*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate;
        for(int &x : nums){
            if(cnt==0){
                candidate = x;
                cnt = 1;
            }else if(x!=candidate){
                cnt--;
            }else{
                cnt++;
            }
        }
        return candidate;
           
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)