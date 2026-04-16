// Implement Atoi
// https://www.geeksforgeeks.org/problems/implement-atoi/1


// Approach I : With Long - Long

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // 2. Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Build number with overflow check
        int ans = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // 🔥 Overflow check BEFORE multiplying
            if (ans > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return ans * sign;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)


// Approach II : with only int data type

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // 2. Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Build number with overflow check
        int ans = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // 🔥 Overflow check BEFORE multiplying
            if (ans > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            // ans*10 + digit > INT_MAX

            ans = ans * 10 + digit;
            i++;
        }

        return ans * sign;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)