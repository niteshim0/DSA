// LC 868. Binary Gap
// https://leetcode.com/problems/binary-gap/description
// Concepts :: Decimal to Binary Conversion


// Approach :: We will calculate the adjacent 1 idx occurence differences on the fly.

class Solution {
public:
    int binaryGap(int n) {
        int idx = 0;
        int oneFound = -1;
        int maxi = 0;
        int temp = n;
        while(temp>0){
            int binary = temp&1;
            if(binary == 1){
                if(oneFound!=-1){
                    int gap = idx - oneFound;
                    maxi = max(maxi,gap);
                }
                oneFound = idx;
            }
            temp/=2;
            idx++;
        }

        return maxi;
    }
};

// Time Complexity : O(1)
// Space Complexity : O(1)