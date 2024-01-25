# String Algorithms 

A real-life use case highlighting the importance of string algorithms is `auto-completion`.

# String Matching Algorithms
1. Brute Force Method
2. Rabin-Karp String Matching Algorithm
3. String Matching with Finite Automata
4. KMP Algorithm
5. Boyer-Moore Algorithm
6. Suffix Trees

## Brute Force Method
For each possible position in the text T, we check whether the pattern P matches or not.

```c++
int bruteForceStringMatch(const string& text, const string& pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();

    for (int i = 0; i <= textLength - patternLength; ++i) {
        int j;
        for (j = 0; j < patternLength; ++j) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == patternLength) {
            // Pattern found at position i
            return i;
        }
    }

    // Pattern not found in the text
    return -1;
}
```
<ol>
 <li>Time Complexity : O((n – m + 1) × m) ≈O(n × m).</li>
 <li>Space Complexity : O(1).</li>
</ol>

# Rabin-Karp String Matching Algorithm

The **Rabin-Karp algorithm** is a string matching algorithm developed by Michael O. Rabin and Richard M. Karp in 1987. It is particularly useful for searching for a pattern of characters within a larger body of text. The algorithm's efficiency comes from its use of hashing to quickly eliminate irrelevant portions of the text.

## Basic Steps of the Rabin-Karp Algorithm:

### 1. Hashing the Pattern and Substrings:

- Compute the hash value of the pattern you are searching for.
- Compute the hash value of the first substring of the text with the same length as the pattern.

### 2. Comparing Hash Values:

- If the hash values match, compare the actual characters of the pattern and substring to check for a match.
- If there is a match, return the current position as a potential match.

### 3. Rolling Hash:

- Move to the next substring by "rolling" the hash. Instead of recomputing the hash from scratch for each substring, update it based on the previous substring's hash.

### 4. Handling Hash Collisions:

- If there is a hash collision (i.e., the hash values match but the substrings don't), compare the substrings character by character to avoid false positives.(Spurious Hits)

### 5. Continue Searching:

- Repeat the process until you reach the end of the text.

The efficiency of the Rabin-Karp algorithm comes from the use of rolling hash, allowing it to compare substrings in constant time. However, it's essential to choose a suitable hash function to minimize hash collisions.

```c++
#include <bits/stdc++.h>

using namespace std;

const int prime = 101;  // A prime number to use in hashing

const int MOD = 1e9 + 7;  // Modulo operation to avoid overflow

int hashString(const string& str, int len) {
    int hashValue = 0;
    for (int i = 0; i < len; ++i) {
        hashValue = (hashValue + (str[i] - 'a' + 1) * pow(prime, i)) % MOD;
    }
    return hashValue;
}

int updateHash(int oldHash, char oldChar, char newChar, int len) {
    int newHash = (oldHash - (oldChar - 'a' + 1) + MOD) % MOD;
    newHash = (newHash * prime) % MOD;
    newHash = (newHash + (newChar - 'a' + 1)) % MOD;
    return newHash;
}

void RabinKarp(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    int patternHash = hashString(pattern, m);
    int textHash = hashString(text, m);

    for (int i = 0; i <= n - m; ++i) {
        if (textHash == patternHash) {
            int j;
            for (j = 0; j < m; ++j) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == m) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Update the rolling hash
        if (i < n - m) {
            textHash = updateHash(textHash, text[i], text[i + m], m);
        }
    }
}

```

# Rabin-Karp Algorithm Time Complexity Analysis

## Average Case:

The average-case time complexity of the Rabin-Karp algorithm is generally considered to be O((n + m) * q), where:

- `n` is the length of the text.
- `m` is the length of the pattern.
- `q` is the average time complexity of the hash function.

This analysis assumes that the hash function distributes hash values uniformly, resulting in fewer hash collisions. With a well-designed hash function, the Rabin-Karp algorithm can exhibit efficient average-case performance.

## Worst Case:

The worst-case time complexity of the Rabin-Karp algorithm remains O((n - m + 1) * m), where:

- `n` is the length of the text.
- `m` is the length of the pattern.

The worst-case scenario arises when hash collisions are frequent, necessitating character-by-character comparison in case of collisions. The choice of the hash function significantly influences the worst-case performance. A poorly chosen hash function or numerous hash collisions can lead to an approach similar to that of a naive pattern matching algorithm.

It's crucial to emphasize that the efficiency of the Rabin-Karp algorithm is highly dependent on the quality of the hash function. A well-designed hash function minimizes collisions, contributing to improved average and worst-case performance. In practical applications, Rabin-Karp is often efficient, especially when used with a good hash function and in scenarios where multiple pattern searches are required in the same text.

</hr>



