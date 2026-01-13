// https://www.geeksforgeeks.org/problems/lemonade-change/1
// Bus Ticket Change
// Concept :: Greedy + Nested If-else

class Solution {
public:
    bool canServe(vector<int>& bills) {
        
        int five = 0, ten = 0;

        for (int bill : bills) {
            if (bill == 5) {
                five++;
            }
            else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            }
            else if (bill == 20) {
            
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)