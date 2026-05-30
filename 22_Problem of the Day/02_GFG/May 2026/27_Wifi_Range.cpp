// 27. Wifi Range
// https://www.geeksforgeeks.org/problems/wifi-range--170647/1

// Concept :: Prefix Sum + Difference Array Approach

// Key Idead :: Take the help of either diff array or prefixSum array(cnt router and ensures that cpable range b/w a router is covered by them)

class Solution {
public:

    bool wifiRange(string &s, int x) {

        int n = s.size();

        vector<int> diff(n + 1, 0);

        // Mark ranges
        for(int i = 0; i < n; i++) {

            if(s[i] == '1') {

                int rangeLeft = max(0, i - x);
                int rangeRight = min(n - 1, i + x);

                diff[rangeLeft]++;

                if(rangeRight + 1 < n)
                    diff[rangeRight + 1]--;
            }
        }

        // Prefix sum
        int cover = 0;

        for(int i = 0; i < n; i++) {

            cover += diff[i];

            if(cover <= 0)
                return false;
        }

        return true;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)

// 2. PrefixSum Approach