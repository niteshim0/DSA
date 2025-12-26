// 2483. Minimum Penalty for a Shop
// https://leetcode.com/problems/minimum-penalty-for-a-shop/description/?envType=daily-question&envId=2025-12-26


// Approach I : Two Pass

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        int totalY = 0;
        for(char c : customers)
            if(c == 'Y') totalY++;

        int penalty = totalY;   
        int minPenalty = penalty;
        int bestHour = 0;

        int leftN = 0;   
        int leftY = 0;   

        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y') leftY++;
            else leftN++;

            int currPenalty = leftN + (totalY - leftY);

            if(currPenalty < minPenalty) {
                minPenalty = currPenalty;
                bestHour = i + 1;
            }
        }
        return bestHour;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)

// Approach II : One Pass

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        int currPenalty = 0;
        int minPenalty = 0;
        int bestHour = 0;

        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y') currPenalty--;
            else currPenalty++;

            if(currPenalty < minPenalty) {
                minPenalty = currPenalty;
                bestHour = i + 1;
            }
        }
        return bestHour;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)