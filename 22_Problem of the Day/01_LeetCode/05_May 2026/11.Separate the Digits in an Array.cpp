// LC 2553 . Separate the Digits in an Array
// https://leetcode.com/problems/separate-the-digits-in-an-array

// Concepts :: Simulation + Arrays


// Approach I :: Iterating array in reverse , and pushing into the vector and in final turn reversing that ans vector

class Solution {
public:
    void breakIntoDigits(vector<int>& ans,int num){

        int temp = num;

        while(temp!=0){
            int rem = temp%10;
            ans.push_back(rem);
            temp/=10;
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;

        for(int i = n - 1 ; i >= 0 ; i--){

            breakIntoDigits(ans,nums[i]);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};

// Time Complexity : O(NlogM)
// Space Complexity : O(N)

// Approach II :: Without Reverse :: Using temporary array or string

// Temporary Array
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> result;

        for (int num : nums) {

            vector<int> temp;

            while(num > 0) {
                temp.push_back(num % 10);
                num/=10;
            }

            for(int i = temp.size() - 1 ; i>=0 ; i--){

                result.push_back(temp[i]);
            }
        }

        return result;
    }
};

// Temporary String

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> result;

        for (int num : nums) {

            string s = to_string(num);

            for (char ch : s) {

                result.push_back(ch - '0');
            }
        }

        return result;
    }
};

// Time Complexity : O(NlogM)
// Space Complexity : O(totalDigits)