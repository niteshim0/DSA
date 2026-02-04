// Last Moment Before All Ants Fall Out
// https://www.geeksforgeeks.org/problems/last-moment-before-all-ants-fall-out-of-a-plank/1
// Concept :: Greedy

// Approach :: Ants walk straight until they fall off because since all are indistinguishable to each other , it doesn't matter whether we simulate or not.

class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeft = 0  , maxRight = 0;
        for(int &x : left){
            maxLeft = max(maxLeft,x);
        }
        
        for(int &x : right){
            maxRight = max(maxRight,n-x);
        }
        
        return max(maxLeft,maxRight);
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)