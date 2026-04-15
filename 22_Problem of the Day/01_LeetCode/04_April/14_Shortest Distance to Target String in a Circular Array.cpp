// LC 2515 Shortest Distance to Target String in a Circular Array
// https://leetcode.com/problems                   shortest-distance-to-target-string-in-a-circular-array



// Concepts :: Two Pointers + Circular Array

// Interview Explaination :: “Since the array is circular, for every occurrence of target I compute both forward and backward distances using min(abs(i - startIndex), n - abs(i - startIndex)) and take the minimum.”

// Approach I :: Two Pointer (Expand Left and Right simultaneously)

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {

        int n = words.size();

        for (int steps = 0; steps < n; steps++) {
            
            int left = (startIndex - steps + n) % n;
            int right = (startIndex + steps) % n;

            if(words[left] == target || words[right] == target){
                 
                return steps;
            }

        }

        return -1;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)


// Approach II :: Math 
// Calculating minimum circular distance by comparing direct and wrap-around paths.

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int dist = abs(i - startIndex);
                mini = min(mini, min(dist, n - dist));
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)