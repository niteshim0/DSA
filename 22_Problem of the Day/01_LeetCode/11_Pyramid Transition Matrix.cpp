// LC 757 : Pyramid Transition Matrix
// https://leetcode.com/problems/pyramid-transition-matrix/?envType=daily-question&envId=2025-12-29
class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool dfs(string bottom) {
        if (bottom.size() == 1) return true;
        if (memo.count(bottom)) return memo[bottom];

        int n = bottom.size();
        vector<string> nextLevels;
        generateNext(bottom, 0, "", nextLevels);

        for (auto &next : nextLevels) {
            if (dfs(next)) {
                return memo[bottom] = true;
            }
        }
        return memo[bottom] = false;
    }

    void generateNext(string &bottom, int idx, string curr, vector<string> &res) {
        if (idx == bottom.size() - 1) {
            res.push_back(curr);
            return;
        }

        string key = bottom.substr(idx, 2);
        if (!mp.count(key)) return;

        for (char ch : mp[key]) {
            generateNext(bottom, idx + 1, curr + ch, res);
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom);
    }
};
