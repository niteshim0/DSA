// Remove Spaces
// https://www.geeksforgeeks.org/problems/remove-spaces0128/1

// Concepts :: String Concatenation + Two Pointers + Built-in functions


// Approach I :: Use New String and concatenate non space character to it and return it

class Solution {
  public:
    string removeSpaces(string& s) {
       
       string ans;
       
       for(char& ch : s){
           
           if(ch !=' ') ans+=ch;
       }
       
       return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)


// Approach II : Two Pointers

class Solution {
  public:
    string removeSpaces(string& s) {
       
       int itr  = 0 , i = 0;
       int n = s.size();
       
       while(i<n){
           
           if(s[i]!=' '){
               s[itr++] = s[i] ;
           }
           i++;
       }
       
       return s.substr(0,itr);
      
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)


// Approach III : Use remove in-built C++ Function

class Solution {
  public:
    string removeSpaces(string& s) {
       
       auto new_end = remove(s.begin(),s.end(),' ');
       
       s.erase(new_end,s.end());
       
       return s;
      
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)