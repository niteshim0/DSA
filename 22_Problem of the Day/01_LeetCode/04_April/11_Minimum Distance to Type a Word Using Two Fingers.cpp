// LC 1320 . Minimum Distance to Type a Word Using Two Fingers

/*
1. The Core Strategy: 

-- "Total Distance - Savings"The most intuitive way to solve this is to find the minimum distance. However, this code flips the logic:

-- Total Distance: It calculates the total distance if you used only one finger to type the entire word (sum).

-- The Saving (max): If you use a second finger, you "save" the distance that the first finger would have traveled.Result: sum - max.


2. The Keyboard Coordinate System :: The keyboard is a 6-column grid. The dist function calculates the Manhattan Distance between two characters:Row: a / 6  Column: a % 6Distance Formula: $|R_1 - R_2| + |C_1 - C_2|$


3. Dynamic Programming Breakdown :: The array dp[j] represents the maximum distance saved when the second finger is currently resting at character j.

The Main Loop:As we iterate through the word (from p to c):d = dist(p, c): This is the distance the first finger must travel if it handles the move.

The inner loop for (int j = 0; j < 26; j++) checks every possible location j where the second finger could be.

dp[j] + d - dist(j, c):If the second finger moves from j to c, we save the distance the first finger would have taken (d), but we cost the distance the second finger actually moves (dist(j, c)).dp[p] = Math.max(dp[p], cur): 

After the transition, the "other" finger is now at the previous character p. We update the DP table to reflect that one finger is now at p while considering the best savings achieved.
*/


class Solution {
public:
    int minimumDistance(string word) {
        
        int dp[26] = {0};

        int maxDistance = 0 ; // if both figers used
        int totalDistance = 0 ; // if one finger used

        int n = word.size();

        auto dist = [](int prev,int next){

              return abs(prev / 6 - next / 6) + abs(prev % 6 - next % 6);

              // 6 cols grid the keyboard
        };

        for(int i = 0 ; i < n - 1 ; i++){

            int prev = word[i] - 65;
            int next = word[i+1] - 65;

            int manHatDistance = dist(prev,next);

            totalDistance+=manHatDistance;

            int curr = 0;

            for(int j = 0 ; j < 26 ; j++){

                curr = max(curr,dp[j] + manHatDistance - dist(j,next));
            }

            dp[prev] = max(dp[prev],curr);
            maxDistance = max(maxDistance,dp[prev]);
        }

        return totalDistance - maxDistance;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)