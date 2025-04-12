class Solution {
  public:
    bool isOperand(char ch){
        return ((ch >= 'A' && ch <= 'Z') || 
                (ch >= 'a' && ch <= 'z') || 
                (ch >= '0' && ch <= '9'));
    }

    string postToInfix(string s) {
        stack<string> st;
        for (char ch : s) {
            if (isOperand(ch)) {
                st.push(string(1, ch));
            } else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string expr = "(" + op2 + ch + op1 + ")";
                st.push(expr);
            }
        }
        return st.top();
    }
};
// Time Complexity : O(2N)
// Space Complexity : O(N)