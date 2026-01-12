// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
// K Sized Subarray Maximum


// Idea :: Deque at all times store element in descennding order , the front one will always be maximum one in that particular subarray.


class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int i = 0 , j = 0;
        int n = arr.size();
        
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