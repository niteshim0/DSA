// https://leetcode.com/problems/rearrange-array-elements-by-sign/

/*1.Brute Force : -Separate the positive and negative elements in two separate arrays.
                : Put them in original array according to condition.*/

vector<int> alternateNumbers(vector<int>&a) {
    // Write your code here.
    vector<int> pos;
    vector<int> neg;
    for(int &num : a){
        if(num<0) neg.push_back(num);
        else pos.push_back(num);
    }
    int i=0,j=0,k=0;
    int m = a.size();
    while(k<m){
        a[k++] = pos[i++];
        a[k++] = neg[j++];
    }
 return a;
}
// Time Complexity : O(2N)
// Space Complexity : O(1)

/*2.Optimal Approach : -Along with iterating rearrange the elements into a new array.*/
class Solution {
  public:
      vector<int> rearrangeArray(vector<int>& nums) {
          int n = nums.size();
          vector<int> ans(n,0);
          int posIdx = 0;
          int negIdx = 1;
          for(int i = 0;i<n;i++){
              if(nums[i]<0){
                  ans[negIdx] = nums[i];
                  negIdx+=2;
              }else{
                  ans[posIdx] = nums[i];
                  posIdx+=2;
              }
          }
          return ans;
      }
  };

// Time Complexity : O(N)
// Space Complexity : O(1)