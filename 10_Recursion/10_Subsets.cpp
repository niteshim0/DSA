// Recursive Version

class Solution {
  public:
      vector<vector<int>> ans;
      void solve(vector<int>& arr,int idx,vector<int>& nums){
          if(idx == nums.size()){
              ans.push_back(arr);
              return;
          }
          arr.push_back(nums[idx]);
          solve(arr,idx+1,nums);
          arr.pop_back();
          solve(arr,idx+1,nums);
      }
      vector<vector<int>> subsets(vector<int>& nums) {
          vector<int> arr;
          solve(arr,0,nums);
          return ans;
      }
  };
// Time Complexity : O(2^N)
// Space Complexity : O(2^N)

// Iterative Version

class Solution {
  public:
      vector<vector<int>> subsets(vector<int>& nums) {
          return subs(nums);
      }
  
  private:
      vector<vector<int>> subs(vector<int>& nums) {
          vector<vector<int>> list;
          list.push_back({});  // Start with the empty subset
          
          for (int num : nums) {
              int n = list.size();
              for (int i = 0; i < n; ++i) {
                  vector<int> internal = list[i];  // Copy existing subset
                  internal.push_back(num);        // Add current number
                  list.push_back(internal);       // Add new subset
              }
          }
          return list;
      }
  };
  