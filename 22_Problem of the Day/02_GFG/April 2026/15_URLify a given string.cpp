// URLify a given string
// https://www.geeksforgeeks.org/problems/urlify-a-given-string--141625/1

// Concepts :: Traversal + String Concatenation

class Solution {
  public:
    string URLify(string &s) {
        
        string add = "%20";
        
        string ans = "";
        
        for(char& ch : s){
            
            if(ch == ' '){
                ans+=add;
            }else{
                ans+=ch;
            }
        }
        
        return ans;
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)