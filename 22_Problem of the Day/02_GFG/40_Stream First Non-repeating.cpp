// Stream First Non-repeating
// https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

class Solution {
  public:
    string firstNonRepeating(string &s) {
        
        vector<int> freq(26,0);
        queue<char> q;
        string ans = "";
        
        for(char &ch : s){
            freq[ch-'a']++;
            q.push(ch);
            while(!q.empty() && freq[q.front()-'a']>1){
                q.pop();
            }
            if(q.empty()) ans.push_back('#');
            else ans.push_back(q.front());
        }
        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)