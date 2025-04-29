class Solution {
  public:
      vector<vector<int>> subsets(vector<int>& nums) {
          int n = nums.size();
          int no_of_subsets =  1<<n;
          vector<vector<int>> ans;
          for(int num = 0;num<no_of_subsets;num++){
              vector<int> vec;
              for(int i = 0;i<n;i++){
                  if(num&(1<<i)){
                      vec.push_back(nums[i]);
                  }
              }
              ans.push_back(vec);
          }
          return ans;
      }
  };
  // Time Complexity : O(2^n * n)
  // Space Complexity : O(N*(size of each individual array))