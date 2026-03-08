// LC 1980.Find Unique Binary String
// https://leetcode.com/problems/find-unique-binary-string/description/

// Concepts :: Bit Manipulation / Enumeration / Hashing

// Approach I : Brute Force Approach
// Keep the given strings in hashset
// Now iterate from 1 to 1<<n and genrate their binary and see is they exist in hashset , if not , that is exactly our answer.

class Solution {
public:
    string decimalToBinary(int num,int n){
        string str = "";
        while(num!=0){
            if(num&1) str = '1' + str;
            else str = '0' + str;
            num/=2;
        }
        if(str.size()<n){
            int diff  = n - str.size();
            for(int i = 0;i<diff;i++){
                str = '0' + str;
            }
        }
        return str;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        int limit = 1<<n;

        unordered_set<string> st;
        for(string& str : nums){
            st.insert(str);
        }

        for(int i = 0;i<limit;i++){
            string str = decimalToBinary(i,n);
            if(st.find(str) == st.end()) return str;
        }

        return "";
    }
};

// Time Complexity : O(N*2^N)
// Space Complexity : O(N*2^N)


// Approach II : Iterate Over Integer Equivalents
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> integers;
        for(string num : nums){
            integers.insert(stoi(num,0,2));
        }

        int n = nums.size();

        for(int num = 0;num<=n;num++){
            if(integers.find(num) == integers.end()){
                string ans = bitset<16>(num).to_string();
                return ans.substr(16-n);
            }
        }

        return "";
    }
};
// Time Complexity : O(N*N)
// Space Complexity : O(N)

// Approach III : Cantor's Diagonal Argument

/* Intuition
Cantor's diagonal argument is a proof in set theory.

While we do not need to fully understand the proof and its consequences, this approach uses very similar ideas.

We start by initializing the answer ans to an empty string. To build ans, we need to assign either "0" or "1" to each index i for indices 0 to n - 1. How do we assign them so ans is guaranteed to be different from every string in nums? We know that two strings are different, as long as they differ by at least one character. We can intentionally construct our ans based on this fact.

For each index i, we will check the ith character of the ith string in nums. That is, we check curr = nums[i][i]. We then assign ans[i] to the opposite of curr. That is, if curr = "0", we assign ans[i] = "1". If curr = "1", we assign ans[i] = "0".

What is the point of this strategy? ans will differ from every string in at least one position. More specifically:

ans differs from nums[0] in nums[0][0].
ans differs from nums[1] in nums[1][1].
ans differs from nums[2] in nums[2][2].
...
ans differs from nums[n - 1] in nums[n - 1][n - 1].
Thus, it is guaranteed that ans does not appear in nums and is a valid answer.

This strategy is applicable because both the length of ans and the length of each string in nums are larger than or equal to n, the number of strings in nums. Therefore, we can find one unique position for each string in nums.
*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        int n = nums.size();
        for(int i = 0;i<n;i++){
            char curr = nums[i][i];
            ans += (curr == '0' ? '1' : '0');
        }
        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)
