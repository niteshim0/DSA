// Reverse the given string
// Convert reversed string to postfix(reverse the '(' and ')');
// reverse the postfix expression

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
    string infixToPrefix(string str){
      reverse(str.begin(),str.end());
      for(int i = 0;i<str.size();i++){
        if(str[i]=='('){
          str[i] = ')';
        }else if(str[i]==')'){
          str[i] = '(';
        }
      }
      str = infixToPostfix(str);
      reverse(str.begin(),str.end());
      return str;
    }
};
// Time Complexity : O(3N)
// Space Complexity : O(N)