// https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1
// Expression contains redundant bracket or not
// Concept :: Stack + Bracket Matching

// Intuition :: Whenever a pairs of bracket contains an operator b/w them , they are not redundant -> they make sense because they are containing that result in that bracket , but if that's not the case then those brackets have no any buisiness being there.

class Solution {
  public:
    bool checkRedundancy(string &s) {
        
        stack<char> st;
        
        for(char& ch : s){
            
            if(ch == '(' || ch == '+' || ch == '-'|| ch == '*'|| ch == '/' ){
                st.push(ch);
            }else if(ch == ')'){
                if(st.top() == '(') return true;
                
                while(!st.empty() && st.top()!='('){
                    st.pop();
                }
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
            }
        }
        
        return false;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)