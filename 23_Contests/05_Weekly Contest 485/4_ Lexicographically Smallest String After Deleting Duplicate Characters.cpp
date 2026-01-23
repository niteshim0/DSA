// LC 3816. Lexicographically Smallest String After Deleting Duplicate Characters
// https://leetcode.com/problems/lexicographically-smallest-string-after-deleting-duplicate-characters/
// During Contest :: Not Solved (only 4 minutes were left when i arrive at this ques)
// During upsolving :: 
/*
Intuition ::
For each element s[i], we check if there exists an element smaller than s[i] just after s[i] (i.e. s[i+1] or later).
If such an element exists, then removing s[i] helps in obtaining a lexicographically smaller string.

Approach :: If stack is empty, push the element.

If not:
while the element on the top of the stack is greater than s[i] and its cnt in string>1, pop it.

After processing all characters, form the string from the stack. -> reverse it.

// Now removing edge case
Let final answer be: "aabcc"
In this case, we can remove the last two 'c' characters
because "aabc" is lexicographically smaller than "aabcc".
"aabc" < "aabcc"
*/

class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        int n = s.size();
        stack<char> st;
        vector<int> hash(26,0);

        for(char& ch : s){
            hash[ch-'a']++;
        }

        for(char& ch : s){
            if(st.empty() || st.top()<=ch){
                st.push(ch);
            }else{
                while(!st.empty() && hash[st.top()-'a']>1 && st.top()>ch){
                    hash[st.top()-'a']--;
                    st.pop();
                }
                st.push(ch);
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
         
        reverse(ans.begin(),ans.end());

        while(ans.size()>1 && hash[ans.back()-'a']>1){
            hash[ans.back()-'a']--;
            ans.pop_back();
        }

        return ans;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)
