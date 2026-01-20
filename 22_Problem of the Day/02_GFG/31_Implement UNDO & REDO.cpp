// Implement UNDO & REDO
// https://www.geeksforgeeks.org/problems/implement-undo-redo/1

class Solution {
  private:
    string text = "";
    vector<char> need;
    stack<char> st;
  public:
    void append(char x) {
        text+=x;
        st.push(x);
    }

    void undo() {
        need.push_back(st.top());
        text.pop_back();
        st.pop();
    }

    void redo() {
        text+=need[need.size()-1];
        st.push(need[need.size()-1]);
        need.pop_back();
    }

    string read() {
       return text;
    }
};
// Time Complexity : O(1)
// Space Complexity : O(N)