// LC 1415. The k-th Lexicographical String of All Happy Strings of Length n
// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/

// Concepts :: Backtracking + Maths

// Approach I :: Generate all the happy strings of length n 
// this adjaceny condition is such that the generated strings will always be in lexographical order
// returns the kth element.

class Solution {
public:
    vector<string> ans;

    void happyStringGenerator(char prev, int n, string need){
        if(need.size() == n){
            ans.push_back(need);
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++){
            if(ch == prev) continue;   
            happyStringGenerator(ch, n, need + ch);
        }
    }

    string getHappyString(int n, int k) {
        for(char start = 'a'; start <= 'c'; start++){
            happyStringGenerator(start, n, string(1, start));
        }

        if(ans.size() < k) return "";
        return ans[k-1];
    }
};
// for happy string -> at first(0) Idx , there are 3 choices , for further (1,n-1) idx , there will always be 2 choices
// so no of happy strings of size n will always be 3*2^(N-1) and each string generation takes N time --> (3*N*(2^N))/2 --> 1.5*N*(2^N) --> N*(2^N)
// Time Complexity : O(N*2^N) 
// Space Complexity : O(N*2^N) // same + O(N) recursion stack (stack will not go further this length because string length is same as n)

// Approach II :: Backtracking + Stopping When K element Completes
class Solution {
public:
    vector<string> ans;
    
    void happyStringGenerator(char prev, int n, string need,int k){
        if(ans.size() == k) return ;
        if(need.size() == n){
            ans.push_back(need);
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++){
            if(ch == prev) continue;   
            happyStringGenerator(ch, n, need + ch,k);
        }
    }

    string getHappyString(int n, int k) {
        for(char start = 'a'; start <= 'c'; start++){
            if(ans.size() == k) break;
            happyStringGenerator(start, n, string(1, start),k);
        }

        if(ans.size() < k) return "";
        return ans[k-1];
    }
};
//Time Complexity : O(n * k)
//Space Complexity : O(n * k)

// Approach III :: Improving Space

class Solution {
public:
    int count = 0;
    string result = "";

    void dfs(char prev, int n, string curr, int k){
        if(curr.size() == n){
            count++;
            if(count == k){
                result = curr;
            }
            return;
        }

        for(char ch='a'; ch<='c'; ch++){

            if(ch == prev) continue;
            dfs(ch,n,curr+ch,k);
            if(result!="") return;
        }
    }

    string getHappyString(int n, int k) {

        for(char start='a'; start<='c'; start++){
            dfs(start,n,string(1,start),k);
            if(result!="") break;
        }

        return result;
    }
};
//Time Complexity : O(n * k)
//Space Complexity : O(n)

// Approach IV :: Now going for Kill (Combinatorics) + Blocking + Binary Exponentiation

class Solution {
public:
    string getHappyString(int n, int k) {

        long long total = (1LL << (n-1)) * 3;
        if(k > total) return "";

        string result(n,'a');

        int startA = 1;
        int startB = startA + (1<<(n-1));
        int startC = startB + (1<<(n-1));

        if(k < startB){
            result[0] = 'a';
            k -= startA;
        }
        else if(k < startC){
            result[0] = 'b';
            k -= startB;
        }
        else{
            result[0] = 'c';
            k -= startC;
        }

        for(int i=1;i<n;i++){

            int mid = 1<<(n-i-1);

            char prev = result[i-1];
            char small, large;

            if(prev=='a'){small='b'; large='c';}
            if(prev=='b'){small='a'; large='c';}
            if(prev=='c'){small='a'; large='b';}

            if(k < mid){
                result[i] = small;
            }else{
                result[i] = large;
                k -= mid;
            }
        }

        return result;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

// Approach 4: Combinatorics

// ------------------> Intuition <--------------------------------------
/*
The main idea of this approach is that we do not need to generate all k−1 happy strings to find the kth smaller one.

To better understand this, let's make the following observations:

The total number of happy strings of length n is 3⋅2^(n−1).
 
This is because the first character has 3 choices ('a', 'b', or 'c') and each subsequent character has 2 choices, as it must differ from the preceding character. Therefore, if k exceeds this total, it implies that the k-th happy string does not exist, and we should return an empty string.

Moving on to the harder case, note that the set of all happy strings can be divided into three equal groups based on their starting character:

-> Strings starting with 'a': positions 1 to 2^(n−1).
-> Strings starting with 'b': positions 2^(n−1)+1 to 2⋅2^(n−1).
-> Strings starting with 'c': positions 2⋅2^(n−1)+ 1 to 3⋅2^(n−1).
 .
Each group contains 2^(n−1)strings, as fixing the first character leaves 2^(n−1)
ways to choose the remaining characters. By comparing k to these ranges, we can determine the first character of the desired string and adjust k to reflect its position within the subgroup by subtracting the group's starting index.

Similarly, every subsequent character at the ith position divides the strings of its group into two subgroups of size 2^(n−i−1).  :

-> Strings starting with the smallest valid character ('a' -> 'b', 'b' -> 'a' and 'c' -> 'a').

-> Strings starting with the greatest valid character ('a' -> 'c', 'b' -> 'c' and 'c' -> 'b').

-> By comparing k with the midpoint at which the groups are split, i.e., 2^(n−i−1)
,we can determine whether the result string belongs to the first or last subgroup and set the character at position i accordingly.
*/
// -------------------Algorithm---------------------------------
/*
1. Calculate the total number of happy strings of length n as total = 3 * pow(2, n - 1).
If k is greater than total, return an empty string.

2. Initialize the result string.

Set the index of the first string that starts with 'a' (startA) to 1 (the lexicographically smallest happy string with 'a').

Calculate the index of the first string that starts with 'b' as startB = startA + pow(2, n - 1).

Calculate the index of the first string that starts with 'c' as startC = startB + pow(2, n - 1).

Determine the first character of the string:
If k is less than startB, set the first character of result to 'a' and subtract startA from k.

Else if k is less than startC, set the first character of result to 'b' and subtract startB from k.
Else, set the first character of result to 'c' and subtract startC from k.

For each subsequent character, at charIndex:
Calculate the midpoint of its group, as midpoint = pow(2, n - charIndex - 1).
If k is less than midpoint, set result[charIndex] = nextSmallest[result[charIndex - 1]] to extend result with the smallest valid character.
Otherwise:
Set result[charIndex] = nextGreatest[result[charIndex - 1]].
Decrement k by midpoint so that it corresponds to the index of the result string within the current group.
Return result.

*/


