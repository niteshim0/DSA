// LC 67. Add Binary
// https://leetcode.com/problems/add-binary/description
// Concepts :: Number to String + String to Number + String reversal + addition

// Approach :: We will travel backwards from both number and add the result , just like we do normal binary addition.

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size() , n = b.size();
        int i = m - 1;
        int j = n - 1;
        int carry = 0;
        string result = "";

        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
// Time Complexity : O(max(m,n))
// Space Complexity : O(1)
