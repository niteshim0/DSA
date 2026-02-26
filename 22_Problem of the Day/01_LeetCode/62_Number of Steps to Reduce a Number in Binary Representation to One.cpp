// LC 1404 . Number of Steps to Reduce a Number in Binary Representation to One
// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2026-02-26

// Concepts :: Odd and Even Concept regarding binary No + string manipulation + Greedy Algorithm

// Approach I : Simulate the process.
class Solution {
public:
    void divideByTwo(string& s){
        s.pop_back();
    }
    void addOne(string& s){
        int n = s.size();
        int i = n - 1;
        while (i >= 0 && s[i] == '1') {
            s[i] = '0';
             i--;
        }
        if (i >= 0) {
            s[i] = '1';
        }else{
            s = '1' + s;
        }
    }
    int numSteps(string s) {
        int steps = 0;
        while (s != "1") {
            if (s.back() == '0') {
               divideByTwo(s);
            }
            else {
                addOne(s);
            }
            steps++;
        }

        return steps;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1) // in C++(strings are mutable) , not in Java or Python(strings are immmutable)


// Approach 2 :: Greedy Algorithm
// If we closely observe the previous approach, we're essentially removing one bit from the right end each time. When the number is even we are directly removing the bit at the rightmost position. In case of an odd number, adding one will make it even, and then we will remove the rightmost bit. Hence, it takes one step to remove the rightmost bit when the number is even, and it takes two steps when the number is odd.

class Solution {
public:
    int numSteps(string s) {
        int N = s.size();

        int operations = 0;
        int carry = 0;
        for (int i = N - 1; i > 0; i--) {
            if (((s[i] - '0') + carry) % 2) {
                operations += 2;
                carry = 1;
            } else {
                operations++;
            }
        }

        return operations + carry;
    }
};

// TC : O(N)
// SC : O(1)