// LC 3714. Longest Balanced Substring II
// https://leetcode.com/problems/longest-balanced-substring-ii

// Core concept :: Prefix Sum + State Matching  + Hash Key Generation

// Approach :: If two positions in the string have the same state, then the substring between them is balanced.
/*
A substring is "balanced" based on different criteria:

"abc" balanced: equal counts of a, b, and c
"ab" balanced: equal counts of a and b (c can be anything)
"bc" balanced: equal counts of b and c (a can be anything)
"ca" balanced: equal counts of c and a (b can be anything)
"a" balanced: no 'a' characters (only b and c)
"b" balanced: no 'b' characters (only a and c)
"c" balanced: no 'c' characters (only a and b)
*/


class Solution {
public:
    int longestBalanced(string S) {
        int N = S.length();
        int ans = 0;
        
        unordered_map<long long, int> first;
        
        int a = 0, b = 0, c = 0;
        
        auto makeKey = [](int type, int v1, int v2) -> long long {
            return ((long long)type << 40) | (((long long)v1 + 100000) << 20) | ((long long)v2 + 100000);
        };
                                                                                                                                                            
        for (int t = 0; t < 7; t++) {
            first[makeKey(t, 0, 0)] = 0;
        }
        
        for (int i = 0; i < N; i++) {
            if (S[i] == 'a') a++;
            else if (S[i] == 'b') b++;
            else c++;
            
            vector<long long> keys = {
                makeKey(0, a - b, a - c),  // abc
                makeKey(1, a - b, c),      // ab
                makeKey(2, b - c, a),      // bc
                makeKey(3, c - a, b),      // ca
                makeKey(4, b, c),          // a
                makeKey(5, c, a),          // b
                makeKey(6, a, b)           // c
            };
            
            for (long long key : keys) {
                auto it = first.find(key);
                if (it != first.end()) {
                    ans = max(ans, i + 1 - it->second);
                } else {
                    first[key] = i + 1;
                }
            }
        }
        
        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)
