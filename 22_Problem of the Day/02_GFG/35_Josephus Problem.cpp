// https://www.geeksforgeeks.org/problems/josephus-problem/1
// Josephus problem
// Concept :: Circular Array Knowledge + diff b/w 0 & 1 indexing vectors + Recursion + Mathematics + Recurrence Relation


// Approach I : Simulate the process on a vector.
class Solution {
  public:
    int josephus(int n, int k) {
        // code here
        vector<int> nums;
        for(int i = 1;i<=n;i++){
            nums.push_back(i);
        }
        int idx = 0;
        while(nums.size()!=1){
            idx = (idx+k-1)%nums.size();
            nums.erase(nums.begin()+idx);
        }
        return nums[0];
    }
};
// Time Complexity : O(N*(N/k))
// Space Complexity : O(N)


// Approach II :: Find the Recurrence Relation , and do what its saying.
// f(n) = (f(n-1) + k) % n
// f(1) = 0;

class Solution {
public:
    int josephus(int n, int k) {
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            ans = (ans + k) % i;
        }
        return ans + 1;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)

// Approach III :: Recursive Version

class Solution {
public:
    int josephus(int n, int k) {
        if (n == 1)
            return 1;

        return (josephus(n - 1, k) + k - 1) % n + 1;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N) (Recursion Stack Space)