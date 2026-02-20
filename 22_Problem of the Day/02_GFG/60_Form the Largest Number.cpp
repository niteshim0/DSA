// Form the Largest Number
// https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
// Concepts :: Sorting + Comparator + Conversion of Int to String + String Concatenation
// Greedy :: A locally optimal choice (best pair ordering) leads to a globally optimal solution.The final number is just a long concatenation.
// Intuition :: The final answer is just a concatenation of numbers
// So for every pair, we ask:
// “Which order gives a bigger number when joined?”


// We will check every two concated string if first one is greater it will occur first.
class Solution {
  public:
    string findLargest(vector<int> &arr) {
        
        vector<string> temp;
        for(int& num : arr){
            temp.push_back(to_string(num));
        }
        
        string res = "";
        
        sort(temp.begin(),temp.end(),[](string& str1,string& str2){
            return str1 + str2 > str2 + str1;
        });
        
        for(string& str : temp){
            res+=str;
        }
        
        return res[0] == '0' ? "0" : res;
        
    }
};

// Time Complexity : O(N) + O(NlogN) + O(N) ~ O(NlogN)
// Space Complexity : O(N) + O(N) ~ O(N)

// Interview Explaination ::
// I convert the numbers to strings and sort them using a custom comparator. For two strings a and b, I compare a+b and b+a. If a+b is larger, I place a before b. This greedy sorting ensures the final concatenation is maximized. I also handle the edge case where all numbers are zero.