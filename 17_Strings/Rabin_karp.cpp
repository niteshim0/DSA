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