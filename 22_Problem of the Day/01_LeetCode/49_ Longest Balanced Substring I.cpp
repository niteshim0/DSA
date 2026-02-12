// LC 3713. Longest Balanced Substring I
// Concept :: Map + Subarray Generation by Brute Force



// Approach :: Brute force whatever the ques is saying.

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            unordered_map<char,int> mp;

            for(int j = i; j < n; j++) {
                mp[s[j]]++; 

                int need = mp[s[j]];
                bool flag = true;

                for(auto &it : mp){
                    if(it.second != need){
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    maxi = max(maxi, j - i + 1);
                }
            }
        }

        return maxi;
    }
};

// Little bit improved version

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            vector<int> freq(26,0);
            int distinct = 0;
            int maxFreq = 0;

            for(int j = i;j<n;j++){
                int idx = s[j] - 'a';

                if(freq[idx] == 0) distinct++;

                freq[idx]++;
                maxFreq = max(maxFreq,freq[idx]);
                int length = j - i + 1;
                if(length == maxFreq*distinct){
                    maxi = max(maxi,length);
                }
            }
        }

        return maxi;
    }
};

// Time Complexity : O(26*N*N)
// Space Complexity : O(26)