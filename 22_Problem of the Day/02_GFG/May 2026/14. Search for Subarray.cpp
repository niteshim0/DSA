// Search for Subarray
// https://www.geeksforgeeks.org/problems/search-for-subarray/1


class Solution {
  public:
    vector<int> buildLPS(vector<int>& pattern){

        int n = pattern.size();
        vector<int> lps(n,0);

        int len;

        for(int i = 1 , len = 0 ; i < n ;){

            if(pattern[i] == pattern[len]){
                lps[i++] = ++len;
            }else{
                if(len) len = lps[len-1];
                else i++;
            }
        }

        return lps;
    }

    vector<int> kmpSearch(vector<int>& text, vector<int>& pattern){

        vector<int> lps = buildLPS(pattern);

        int i = 0 , j = 0;
        
        vector<int> ans;

        while( i < text.size()){

            if(text[i] == pattern[j]){
                i++; j++;
                if(j == pattern.size()){
                    ans.push_back(i-pattern.size());
                    j = lps[j-1];
                }
            }else{
                if(j) j = lps[j-1];
                else i++;
            }
        }

        return ans;
    }
    vector<int> search(vector<int> &text, vector<int> &pattern) {
        
        return kmpSearch(text,pattern);
        
    }
};


// Time Complexity : O(N + M)
// Space Complexity : O(M)

/*
======================== STRING PATTERN MATCHING ROADMAP ========================

PROBLEM TYPE:
Find all occurrences of pattern inside text.

Example:
Text    = "ababcab"
Pattern = "ab"

===============================================================================
1. BRUTE FORCE PATTERN MATCHING
===============================================================================

IDEA:
Try matching pattern from every index.

TIME:
Worst = O(n*m)

CONCEPTS:
- Nested loops
- Sliding comparison
- Basic matching

IMPORTANT QUESTIONS:
1. Implement strstr()
2. First occurrence in string
3. Naive pattern matching

-------------------------------------------------------------------------------
2. RABIN KARP (ROLLING HASH)
-------------------------------------------------------------------------------

IDEA:
Compare hashes instead of full substrings.

TIME:
Average = O(n+m)
Worst  = O(n*m) due to collisions

CONCEPTS:
- Rolling hash
- Polynomial hashing
- Modular arithmetic

IMPORTANT QUESTIONS:
1. Rabin Karp
2. Repeated DNA sequences
3. Longest duplicate substring

-------------------------------------------------------------------------------
3. KMP (KNUTH MORRIS PRATT)
-------------------------------------------------------------------------------

MOST IMPORTANT STRING ALGORITHM.

IDEA:
Reuse previous matched information using LPS array.

KEY OBSERVATION:
Never move text pointer backward.

TIME:
O(n+m)

CONCEPTS:
- LPS array
- Prefix function
- Failure function
- Prefix-suffix relationships
- Reusing previous work

IMPORTANT QUESTIONS:
1. KMP implementation
2. Repeated substring pattern
3. Longest happy prefix
4. Shortest palindrome
5. String rotation
6. Prefix occurrence count
7. Minimum chars to add for palindrome

VERY IMPORTANT:
After complete match:
j = lps[j-1]
NOT j = 0

-------------------------------------------------------------------------------
4. Z ALGORITHM
-------------------------------------------------------------------------------

IDEA:
For every index, calculate longest substring matching prefix.

TIME:
O(n+m)

CONCEPTS:
- Z-array
- Window reuse
- Prefix optimization

IMPORTANT QUESTIONS:
1. Pattern matching using Z
2. Longest common prefix problems
3. String compression
4. Distinct substrings

-------------------------------------------------------------------------------
5. FINITE AUTOMATA MATCHING
-------------------------------------------------------------------------------

IDEA:
Convert pattern into state machine.

TIME:
Preprocessing = O(m * alphabet)
Searching     = O(n)

CONCEPTS:
- DFA
- State transitions
- Automata theory

-------------------------------------------------------------------------------
6. BOYER MOORE
-------------------------------------------------------------------------------

IDEA:
Match from right to left.
Jump many positions on mismatch.

BEST PRACTICAL PERFORMANCE.

CONCEPTS:
- Bad character heuristic
- Good suffix heuristic

-------------------------------------------------------------------------------
7. SUFFIX ARRAY
-------------------------------------------------------------------------------

IDEA:
Store all suffixes sorted.
Binary search pattern.

TIME:
Build  = O(n log n)
Search = O(m log n)

CONCEPTS:
- Lexicographical sorting
- Binary search on strings
- Prefix comparisons

IMPORTANT QUESTIONS:
1. Longest repeated substring
2. Distinct substrings
3. Longest common substring

-------------------------------------------------------------------------------
8. SUFFIX TREE
-------------------------------------------------------------------------------

ADVANCED STRING DS.

TIME:
Build  = O(n)
Search = O(m)

CONCEPTS:
- Compressed trie
- Ukkonen algorithm

-------------------------------------------------------------------------------
9. AHO CORASICK
-------------------------------------------------------------------------------

MULTIPLE PATTERN MATCHING.

IDEA:
Trie + KMP failure links.

USED IN:
- Antivirus
- Search engines
- DNA matching

TIME:
O(text + patterns + matches)

CONCEPTS:
- Trie
- Failure links
- Automata

===============================================================================
MOST IMPORTANT CORE CONCEPTS
===============================================================================

1. REUSING PREVIOUS WORK
   - KMP
   - DP
   - Memoization

2. PREFIX / SUFFIX RELATIONSHIPS
   - KMP
   - Z Algorithm
   - Palindrome problems

3. WINDOW REUSE
   - Z Algorithm
   - Sliding window

===============================================================================
BEST LEARNING ORDER
===============================================================================

1. Brute Force
2. Rolling Hash
3. KMP
4. Z Algorithm
5. Trie
6. Aho-Corasick
7. Suffix Array
8. Suffix Tree

===============================================================================
MUST MASTER FOR INTERVIEWS
===============================================================================

HIGH PRIORITY:
- KMP
- Z Algorithm
- Rolling Hash
- Trie

BONUS:
- Aho-Corasick

ELITE:
- Suffix Array
- Suffix Tree

===============================================================================
MOST IMPORTANT TAKEAWAY
===============================================================================

BRUTE FORCE:
Text pointer moves backward.

KMP:
Pattern pointer moves backward using LPS.

THAT is the optimization.

===============================================================================
*/