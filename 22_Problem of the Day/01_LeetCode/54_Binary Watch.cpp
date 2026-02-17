// LC 401. Binary Watch
// https://leetcode.com/problems/binary-watch/description/
// Concepts :: Binary Number Understanding + Simple Addition + Enumeration


// Approcah :: We will generate all the possible hours and minutes combination , and check is it giving the same no of bits turned on which we are allowed to turn on exactly.

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int h = 0;h<12;h++){
            for(int m = 0;m<60;++m){
                if(__builtin_popcount(h) + __builtin_popcount(m) == turnedOn){
                    ans.push_back(to_string(h) + ":" + (m<10 ? "0" : "") + to_string(m));
                }
            }
        }

        return ans;
    }
};

// Time Complexity : O(720) ~ O(1)
// Space Complexity : O(1)