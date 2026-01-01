// LC 66 . Plus One
// https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        for(int i = n-1;i>=0;i--){
            int sum = carry;
            sum+=digits[i];
            if(i == n-1) sum+=1;
            digits[i] = sum%10;
            carry = sum/10;
        }
        if(carry!=0){
            digits.insert(digits.begin(), carry);

        }

        return digits;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)


// Approach II :: 

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i = n-1;i>=0;i--){
            if(digits[i]<9){
               digits[i]++;
               return digits;
            }
            digits[i] = 0;
        }

        vector<int> v(n+1,0);
        v[0] = 1;
        return v;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N) // in certain cases of all 9's