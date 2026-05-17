// Make the Array Beautiful
// https://www.geeksforgeeks.org/problems/make-the-array-beautiful--170647/1

// Concepts :: Stack + Stack simulation / cancellation pattern + 

class Solution {
public:
    vector<int> makeBeautiful(vector<int> arr) {
        
        vector<int> ans;
        ans.clear();

        for (int i = 0; i < arr.size(); i++) {
            
            if(ans.size()){
                if((ans.back() >= 0 && arr[i] < 0) ||( ans.back() < 0 && arr[i] >= 0)){
                    ans.pop_back();
                    continue;
                }
            }
            
            ans.push_back(arr[i]);
        }

        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)


// Concepts to Further Enhance

/*

STACK PATTERN CHECKLIST

1. Current element interacts with previous?

2. Removal/cancellation happening?

3. Need nearest greater/smaller?

4. Multiple pops possible?
   => while loop

5. Maintain state with stack

Related:
Valid Parentheses
Asteroid Collision
Remove K Digits
Daily Temperatures
Largest Rectangle
Stock Span
Car Fleet
*/
