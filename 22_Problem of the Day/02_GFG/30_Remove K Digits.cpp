// Remove K Digits
// https://www.geeksforgeeks.org/problems/remove-k-digits/1
// Concept :: Stack + NSE + NGE

// Approach :: 
/*
1. Start from the MSB side and move towards LSB.
2. Push elements onto the stack.
3. If st.top() > s[i] , remove elements from the stack , till this condition holds.
4. If string ends , but not our removal , then remove that many elements from the stack if its not empty in between the process.
5. Take out the elements from the string and concanete it to a ans string.
6. Reverse it , and thats our answer.
*/

class Solution {
  public:
    string removeKdig(string &s, int k) {
        
        stack<char> st;
        int n = s.size();
        for(int i = 0;i<n;i++){
            
            while(!st.empty() && k>0 && s[i]<st.top()){
                k--;
                st.pop();
            }
            if(st.empty() && s[i] == '0') continue;
            st.push(s[i]);
        }
        
        while(k>0 && !st.empty()){
            k--;
            st.pop();
        }
        
        if(st.empty()) return "0";
        
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// Time Complexity : O(N + K)
// Space Complexity : O(N)