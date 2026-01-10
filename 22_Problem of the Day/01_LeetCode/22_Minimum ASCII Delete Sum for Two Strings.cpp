// LC 712. Minimum ASCII Delete Sum for Two Strings
// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
// Concept :: Lowest Common Subsequence + what is the difference b/w pass by reference vs pass by value(which consumes memory again and again)

// Approach I : Memoizaation Approach (Top Down Approach)
class Solution {
public:
    vector<vector<int>> memo;
    int maxSolver(string& s1,string& s2,int idx1,int idx2){
        if(idx1 == s1.size() || idx2 == s2.size()){
            return 0;
        }

        if(memo[idx1][idx2]!=-1) return memo[idx1][idx2];

        int res = 0;

        if(s1[idx1] == s2[idx2]){
            res = int(s1[idx1]) + int(s2[idx2]) + maxSolver(s1,s2,idx1+1,idx2+1);
        }else{
            int skip1 = maxSolver(s1,s2,idx1+1,idx2);
            int skip2 = maxSolver(s1,s2,idx1,idx2+1);
            res = max(skip1,skip2);
        }

       
        return memo[idx1][idx2] = res;
    }
    int minimumDeleteSum(string s1, string s2) {

        int n = s1.size() , m = s2.size();
        memo.resize(n+1,vector<int>(m+1,-1));

        long long firstSum = 0 , secondSum = 0;
        for(char& ch : s1){
            firstSum+=(int)(ch);
        }
        for(char& ch : s2){
            secondSum+=(int)(ch);
        }

        return (firstSum + secondSum) - maxSolver(s1,s2,0,0);

        
    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(N*M) + O(N+M)(Recursion Depth) ~ O(N*M)


// Approach II :: Tabulation Approach (Bottom - Up Approach)
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {

        int n = s1.size() , m = s2.size();
        vector<vector<int>> tab(n+1,vector<int>(m+1,0));

        long long firstSum = 0 , secondSum = 0;

        for(char& ch : s1) firstSum+=(int)(ch);
        for(char& ch : s2) secondSum+=(int)(ch);
        
        // Base Case(already included during inititalization of tab array)
        for(int i = 0;i<=n;i++){
            tab[i][m] = 0;
        }

        for(int j = 0;j<=m;j++){
            tab[n][j] = 0;
        }

        // two loops

        for(int idx1 = n-1;idx1>=0;idx1--){
            for(int idx2 = m-1;idx2>=0;idx2--){

                int res = 0;

                if(s1[idx1] == s2[idx2]){
                    res = int(s1[idx1]) + int(s2[idx2]) + tab[idx1+1][idx2+1];
                }else{
                    int skip1 = tab[idx1+1][idx2];
                    int skip2 = tab[idx1][idx2+1];
                    res = max(skip1,skip2);
                }
                tab[idx1][idx2] = res;
            }
        }

        return (firstSum + secondSum) - tab[0][0];

    }
};


// Time Complexity : O(N*M)
// Space Complexity : O(N*M)


// Approach III :: Space Optimized Approach

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {

        int n = s1.size() , m = s2.size();

        long long firstSum = 0 , secondSum = 0;

        for(char& ch : s1) firstSum+=(int)(ch);
        for(char& ch : s2) secondSum+=(int)(ch);

        vector<int> next(m+1,0); // base case is in initialization
        vector<int> curr(m+1,0);

        for(int idx1 = n-1;idx1>=0;idx1--){
            for(int idx2 = m-1;idx2>=0;idx2--){

                int res = 0;

                if(s1[idx1] == s2[idx2]){
                    res = int(s1[idx1]) + int(s2[idx2]) + next[idx2+1];
                }else{
                    int skip1 = next[idx2];
                    int skip2 = curr[idx2+1];
                    res = max(skip1,skip2);
                }
                curr[idx2] = res;
            }
            next = curr;
        }

        return (firstSum + secondSum) - next[0];

    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(M)