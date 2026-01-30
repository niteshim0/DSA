// Interleave the First Half of the Queue with Second Half
// https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1

class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        vector<int> need;
        while(!q.empty()){
            need.push_back(q.front());
            q.pop();
        }
        int n = need.size();
        int half = n/2;
        if(n&1) half+=1;
        int idx1 = 0 , idx2 = half;
        while(idx1<half && idx2<n){
            q.push(need[idx1++]);
            if(idx2<(n)) q.push(need[idx2++]);
        }
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)