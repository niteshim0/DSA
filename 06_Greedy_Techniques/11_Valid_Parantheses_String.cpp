class Solution {
  public:
      bool helper(string s,int idx,int cnt){
          if(cnt<0) return false;
          if(idx==s.size()){
              return (cnt==0);
          }
          if(s[idx]=='('){
              return helper(s,idx+1,cnt+1);
          }
          if(s[idx]==')'){
              return helper(s,idx+1,cnt-1);
          }
          return  helper(s,idx+1,cnt+1)||helper(s,idx+1,cnt-1)||helper(s,idx+1,cnt);
      }
      bool checkValidString(string s) {
          return helper(s,0,0);
      }
  };
// Time Complexity : O(3^N)
// Space Complexity : O(3^N)(Auxiliary Stack Space)

// Dynamic Programming 
class Solution {
  public:
      unordered_map<int, unordered_map<int, bool>> memo;
  
      bool helper(string& s, int idx, int cnt) {
          if (cnt < 0) return false;
          if (idx == s.size()) return cnt == 0;
  
          if (memo.count(idx) && memo[idx].count(cnt)) {
              return memo[idx][cnt];
          }
  
          bool res = false;
          if (s[idx] == '(') {
              res = helper(s, idx + 1, cnt + 1);
          } else if (s[idx] == ')') {
              res = helper(s, idx + 1, cnt - 1);
          } else {
              res = helper(s, idx + 1, cnt + 1) ||
                    helper(s, idx + 1, cnt - 1) ||
                    helper(s, idx + 1, cnt);
          }
  
          memo[idx][cnt] = res;
          return res;
      }
  
      bool checkValidString(string s) {
          return helper(s, 0, 0);
          
      }
  };
// Time Complexity : O(N+N)
// Space Complexity : O(N+N)  

class Solution {
  public:
      bool checkValidString(string s) {
          int mini = 0;
          int maxi = 0;
          int n = s.size();
          for(int i = 0;i<n;i++){
              if(s[i]=='('){
                  mini = mini + 1;
                  maxi = maxi+1;
              }else if(s[i]==')'){
                  mini = mini-1;
                  maxi = maxi-1;
              }else{
                  mini = mini-1;
                  maxi = maxi+1;
              }
              if(mini<0) mini = 0;
              if(maxi<0) return false;
          }
          return mini == 0;
      }
  };
  // Time Complexity : O(N)
  // Space Complexity: O(1)