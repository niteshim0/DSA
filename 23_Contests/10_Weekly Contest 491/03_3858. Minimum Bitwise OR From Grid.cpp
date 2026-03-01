// LC 3858. Minimum Bitwise OR From Grid
// https://leetcode.com/problems/minimum-bitwise-or-from-grid/

// Concept :: BitMasking + Bit Manipulation Concept


// Approach :: Its good question
// I have to choose one element from each row , such that ans becomes minimum one
// how one can do 
// I will choose such number such that they have same bit in their positon , no increase in number 
// that's what i will do for every bit , if there is no any other possible option than changing the bit , then i will change it
// in each of the bit iteration , i will try to change that set bit to unset bit.


class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {

        long long mask = (1ll<<28) - 1; 

        int n = grid.size();

        for(int bit = 27;bit>=0;bit--){
            int newMask = (mask^(1<<bit));
            bool forbiddenBit = true;

            for(int i = 0;i<n;i++){
                bool elementFound = false;
                for(int& x : grid[i]){
                    if((x|newMask) == newMask){
                        elementFound = true;
                        break;
                    }
                }
                if(!elementFound){
                    forbiddenBit = false; 
                    break;
                }
            }

            if(forbiddenBit){
                mask = newMask ; 
            }
        }
        return mask;
    }
};

// Time Complexity : O(28*N*M)
// Space Complexity : O(1)