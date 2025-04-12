class Solution {
  public:
    int priority(char ch){
        if(ch=='^') return 3;
        else if(ch=='*' || ch=='/') return 2;
        else if(ch=='+' || ch=='-') return 1;
        return -1;
    }
    bool isOperand(char ch){
        return ((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'));
    }
    string infixToPostfix(string& s) {
        int n = s.size();
        int i = 0;
        string ans = "";
        stack<char> st;
        while(i<n){
            if(isOperand(s[i])){
                ans+=s[i];
            }else if(s[i]=='('){
                st.push(s[i]);
            }else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }else{
                while(!st.empty()&&priority(s[i])<=priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)