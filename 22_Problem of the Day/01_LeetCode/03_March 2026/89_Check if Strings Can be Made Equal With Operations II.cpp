// LC 2840. Check if Strings Can be Made Equal With Operations II
// https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description

// Concepts :: Counting + Array + Swapping


// Approach :: In both the strings , if they get sorted , elements at even and odd position should be same in both the strings


// Technique 1 :: Sorting

class Solution {
public:
    bool checkStrings(string s1, string s2) {
         
        int n = s1.size();
        
        vector<char> firstOdd , secondOdd , firstEven , secondEven;

        for(int i = 0 ;i < n; i++){

            if(i&1){
                firstOdd.push_back(s1[i]);
                secondOdd.push_back(s2[i]);
            }else{
                firstEven.push_back(s1[i]);
                secondEven.push_back(s2[i]);
            }
        }

        sort(firstOdd.begin(),firstOdd.end());
        sort(secondOdd.begin(),secondOdd.end());
        sort(firstEven.begin(),firstEven.end());
        sort(secondEven.begin(),secondEven.end());

        return (firstOdd == secondOdd) && (firstEven == secondEven);
    }
};

// Time Complexity : O(NLogN)
// Space Complexity : O(N)



// Appraoch II : Frequency Array

class Solution {
public:
    bool isEqual(vector<char>& first , vector<char>& second){

        vector<int> hash(26,0);

        for(char& ch : first){
            hash[ch-'a']++;
        }

        for(char& ch : second){
            hash[ch-'a']--;
        }

        for(int i = 0;i<26;i++){
            if(hash[i]!=0) return false;
        }

        return true;
    }
    bool checkStrings(string s1, string s2) {
         
        int n = s1.size();
        
        vector<char> firstOdd , secondOdd , firstEven , secondEven;

        for(int i = 0 ;i < n; i++){

            if(i&1){
                firstOdd.push_back(s1[i]);
                secondOdd.push_back(s2[i]);
            }else{
                firstEven.push_back(s1[i]);
                secondEven.push_back(s2[i]);
            }
        }

        return isEqual(firstOdd, secondOdd) && isEqual(firstEven, secondEven);
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)


// Approach 1: Hash Table | Frequency Counting
/*Since characters can only move within the same parity, we only need to check whether the two strings contain the same characters in:

all even, and all odd positions
So we compare the character frequencies of these two groups separately.

We can merge the two parity groups into one frequency array.

indices [0...25] are used for characters at even positions
indices [26...51] are used for characters at odd positions
So the same letter is counted in different slots depending on whether it appears at an even or odd index.

Then we scan both strings once:

add the character from s1.
subtract the character from s2.
If both strings contain exactly the same characters at even positions and also at odd positions, then every count becomes 0.*/

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        int freq[52] = {};

        for(int i = 0;i<n;i++){
            
            int offset = (i&1)*26;
            freq[s1[i]-'a' + offset]++;
            freq[s2[i]-'a' + offset]--;
        }

        for(int i = 0;i<52;i++){
            
            if(freq[i]!=0) return false;
        }

        return true;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

/*
Approach 2: Prime Factor Hash
Another way to represent a multiset of characters is to map each letter to a distinct prime number:

a=2, b=3, c=5,  …,   x=89, y=97, z=101
​
 
Then, for each parity group, multiply the primes of all characters in that group together.

Because prime factorization is unique, two groups will produce the same product if and only if they contain the same characters with the same frequencies.

So again, we treat:

all even positions as one group
all odd positions as another group
If the prime-product hash matches for both parity groups, then the strings can be made equal.

This approach should only be used in languages with built-in big integer support.
*/

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int prime[26] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                         43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

        const long long mod = 1000000007; //cap accumulated value w/ min hash collision
        array<long long, 2> h1 = {1, 1}, h2 = {1, 1};

        for (int i = 0; i < s1.length(); i++) {
            int off = i & 1;
            h1[off] = (h1[off] * prime[s1[i] - 'a']) % mod;
            h2[off] = (h2[off] * prime[s2[i] - 'a']) % mod;
        }

        return h1 == h2;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

