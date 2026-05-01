// 01 . Kth Largest in a Stream
// https://www.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1

// Concepts :: Priority Queue + MinHeap + Sliding Window

// Approach :: Push elements in the minheap , if its contain greater than k elements delete top element , then top element will always be the Kth largest 

class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        vector<int> ans;
        
        for(int& x : arr){
            
            pq.push(x);
            if(pq.size() > k) pq.pop();
            
            (pq.size() < k ) ? ans.push_back(-1) : ans.push_back(pq.top());
        }
        
        return ans;
        
    }
};

// Time Complexity : O(N * logN)
// Space Complexity : O(k)