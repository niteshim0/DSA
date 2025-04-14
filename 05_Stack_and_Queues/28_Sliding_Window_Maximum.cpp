class Solution {
  public:
      vector<int> maxSlidingWindow(vector<int>& nums, int k) {
          int i = 0;
          int j = 0;
          int n = nums.size();
          deque<int> list;
          vector<int> ans;
          while(j<n){
              while(list.size()>0 && list.back()<nums[j]){
                  list.pop_back();
              }
              list.push_back(nums[j]);
              if(j-i+1<k){
                  j++;
              }
              else if(j-i+1==k){
                  ans.push_back(list.front());
                  if(nums[i] == list.front()){
                      list.pop_front();
                  }
                  i++;
                  j++;
              }
          }
          return ans;
  
      }
  };
  // Time Complexity : O(N+N)
  // Space Complexity : O(N+N)