//  https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
// K Sized Subarray Maximum
// Concept :: Sliding Window(Fixed Window Size)

// Approach :: We will use deque so that , we can know what's at front,
// what's at back
// in the meanwhile maintain whatever element will be at front of deque will be the maximum one

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        
        int n = arr.size();
        int i = 0 , j = 0;
        deque<int> dq;
        vector<int> ans;
        
        while(j<n){
            
            while(!dq.empty() && arr[dq.back()]<=arr[j]){
                dq.pop_back();
            }
            
            dq.push_back(j);
            
            if(j-i+1 == k){
                
                if(!dq.empty() && dq.front() < i){
                    dq.pop_front();
                }
                
                ans.push_back(arr[dq.front()]);
                i++;
            }
            
            j++;
        }
        
        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(k)
