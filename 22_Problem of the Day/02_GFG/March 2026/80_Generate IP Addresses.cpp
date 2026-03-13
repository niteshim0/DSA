// Generate IP Addresses
// https://www.geeksforgeeks.org/problems/generate-ip-addresses/1

// Concepts :: String + BackTracking

class Solution {
public:
    vector<string> ans;

    bool isValid(string &s,int start,int len){
        if(start+len > s.size()) return false;

        if(len > 1 && s[start] == '0') return false;

        int num = 0;
        for(int i=0;i<len;i++){
            num = num*10 + (s[start+i]-'0');
        }

        return num <= 255;
    }

    void backtrack(string &s,int idx,int parts,string curr){
        
        if(parts == 4 && idx == s.size()){
            curr.pop_back(); 
            ans.push_back(curr);
            return;
        }

        if(parts == 4) return;

        for(int len=1; len<=3; len++){
            if(isValid(s,idx,len)){
                backtrack(s, idx+len, parts+1, 
                          curr + s.substr(idx,len) + ".");
            }
        }
    }

    vector<string> generateIp(string &s) {
        backtrack(s,0,0,"");
        return ans;
    }
};
// TC : O(1)
// SC : O(1)
