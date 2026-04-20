// 2078. Two Furthest Houses With Different Colors
// https://leetcode.com/problems/two-furthest-houses-with-different-colors/


// Concepts :: Two Pointers
// Since the distance increases as the two houses are farther apart, the optimal pair should stretch as much as possible across the street.
// Hence, it is enough to compare houses against the two ends.

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int n = colors.size();

        int left = 0 , right = 0;

        for(int i = 0 ; i < n ; i++){

            if(colors[i] ^ colors[n-1]){
                left = i;
                break;
            }
        }

        for(int i = n - 1 ; i >= 0 ; i--){

            if(colors[i] ^ colors[0]){
                right = i;
                break;
            }
        }

        return max(n-1-left, right);
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)


class Solution {
public:
    int maxDistance(vector<int>& A) {
        int j = A.size();

        for (int i = 0; i < j; i++)
            if ((A[i] ^ A.back()) | (A[j - 1 - i] ^ A[0]))
                return j - 1 - i;

        return 0;
    }
};