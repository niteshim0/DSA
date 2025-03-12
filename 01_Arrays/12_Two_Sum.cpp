//https://leetcode.com/problems/two-sum/

/*1.Brute Force Approach : - Take two nested loops i and j such that j = i+1;
                           - If sum of nums[i]+nums[j]==target return the indices.*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};

// Time Complexity : O(N*N - N)
// Space Complexity : O(2)

/*2.Better Approach : Use the hashmap to store the elements and their indices.
                      Along with check whether target-nums[i] exist in hashmap or not.
                      If exist return mp[target-nums[i]],i; */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++){
            int remsum = target-nums[i];
            if(mp.find(remsum)!=mp.end()){
                return {mp[remsum],i};
            }
            mp[nums[i]] = i;
        }
        return {-1,-1};  
    }
};

// Time Complexity : O(NLogN)(ordered_map) , O(N)(unordered(avg or best case), O(N*N)(worst unordered))
// Space Complexity : O(N)

/*3.Optimal Approach : Sort the array.(Its only optimal if ans would be yes or no.)
                       Use the two pointer concept.*/
//https://www.naukri.com/code360/problems/reading_6845742?leftPanelTabValue=SUBMISSION
#include<bits/stdc++.h>
string read(int n, vector<int> nums, int target)
{
 sort(nums.begin(),nums.end());
 int i = 0;
 int j = n-1;
 while(i<j){
     int need = nums[i] + nums[j];
     if(need == target){
         return "YES";
     }else if(need<target){
         i++;
     }else{
         j--;
     }
 }
 return "NO";
}
//Time Complexity : O(NlogN)
//Space Complexity : O(1)
