// LC 1674. Minimum Moves to Make Array Complementary
// https://leetcode.com/problems/minimum-moves-to-make-array-complementary/description


// Concept :: Greedy + Range Contribution Technique + Difference Array + Sweep Line Algorithm + Prefix Sum

// Key Idea : We have to choose a targetSum , that's the whole game.
// Using a difference array to efficiently calculate move counts for all possible target sums via prefix sums.

// Approach I : Brute Force Approach

class Solution {
public:

    int costIncurred(vector<int>& nums, int target, int limit){

        int n = nums.size();
        int cost = 0;

        for(int i = 0 ; i < n/2 ; i++){

            int a = min(nums[i], nums[n-i-1]);
            int b = max(nums[i], nums[n-i-1]);

            if(a + b == target){
                continue;
            }

            else if(target >= a + 1 && target <= b + limit){
                cost += 1;
            }

            else{
                cost += 2;
            }
        }

        return cost;
    }

    int minMoves(vector<int>& nums, int limit) {

        int ans = INT_MAX;

        for(int target = 2 ; target <= 2 * limit ; target++){

            ans = min(ans, costIncurred(nums, target, limit));
        }

        return ans;
    }
};

// Time Complexity : O(N * N)
// Space Complexity : O(1)

// Approach II :: Line Sweep + Difference Array + Prefix Sum

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        
        int n = nums.size();
        vector<int> diff(2*limit + 2, 0);

        for(int i = 0 ; i < n/2 ; i++){

            diff[2]+=2;
            diff[2*limit+1]-=2;

            int a = min(nums[i],nums[n-i-1]);
            int b = max(nums[i],nums[n-i-1]);

            diff[a+1]-=1;
            diff[b+limit+1]+=1;

            diff[a+b]-=1;
            diff[a+b+1]+=1;

        }

        int ans = INT_MAX;
        int curr = 0;

        for(int target = 2 ; target <= 2 * limit ; target++){
            
            curr+=diff[target];
            ans = min(ans,curr);
        }

        return ans;
    }
};

// Time Complexity : O(N + LIMIT)
// Space Complexity : O(N)


/*
// Concepts need to master to solve this problem
| Problem       | Concept               |
| ------------- | --------------------- |
| LeetCode 560  | Prefix Sum            |
| LeetCode 370  | Difference Array      |
| LeetCode 1094 | Sweep Line            |
| LeetCode 1109 | Range Updates         |
| LeetCode 1674 | Full Combination      |
| LeetCode 798  | Advanced Contribution |
| LeetCode 732  | Sweep + Segment Tree  |

// Order to Solve
560
370
1109
1094
1674
798
307
732
715
435
239
84
*/



