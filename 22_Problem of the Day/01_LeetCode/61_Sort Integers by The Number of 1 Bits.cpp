// LC 1356. Sort Integers by The Number of 1 Bits
// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/

// Concepts :: Sorting + Comparator Knowledge + Hamming Weight(builtin methods to calculate it) + Brian Kerninghan's Algorithm


// Approach I :: Sort By Custom Comparator: Built-in
// Use built-in methods to define a custom comparator that uses the hamming weight of a number.
// Sort arr with the custom comparator.
// Return arr.

class Solution {
public:
    static bool cmp(int& a , int& b){
        int setBit1 = __builtin_popcount(a);
        int setBit2 = __builtin_popcount(b);
        
        if(setBit1 == setBit2) return a<b;

        return setBit1 < setBit2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};

// Time Complexity : O(NlogN)
// Space Complexity : O(logN)

// Space Complexity: O(logn) or O(n)

// The space complexity of the sorting algorithm depends on the implementation of each programming language:

// In Java, Arrays.sort() for primitives is implemented using a variant of the Quick Sort algorithm, which has a space complexity of O(logn)
// In C++, the sort() function provided by STL uses a hybrid of Quick Sort, Heap Sort and Insertion Sort, with a worst case space complexity of O(logn)
// In Python, the sort() function is implemented using the Timsort algorithm, which has a worst-case space complexity of O(n)

// Approach 2: Bit Manipulation
// Instead of using builtin methods to calculate set bits(Hamming Weight) , we will do it manually.

class Solution {
public:
    static int findWeight(int num){
        
        int wt = 0;
        while(num>0){
            if(num&1) wt++;
            num>>=1;
        }
        return wt;
    }
    static bool cmp(int& a , int& b){
        int setBit1 = findWeight(a);
        int setBit2 = findWeight(b);

        if(setBit1 == setBit2) return a<b;

        return setBit1 < setBit2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};
// TC : O(NlogN)
// SC : O(logN)

// Approach 3: Brian Kerninghan's Algorithm

// There is a better way to find the hamming weight of a number. Brian Kerninghan's algorithm is an elegant and efficient way to find the number of set bits in a number.

// For a given num, we run the algorithm until num = 0, that is the algorithm runs until there are no more set bits. At each iteration, we remove the least significant bit in num. Once all the bits are removed, num = 0 and the algorithm terminates. The number of iterations is the number of set bits since we remove one bit per iteration.

// So how do we remove the least significant bit (LSB)? All we need to do is AND num with num - 1. That is, num &= (num - 1).

// We only travel number of set bits , not all bits of a num , it doesn't seems to be much improved version , but if datasets will be very larget , it will give significant boost to the whole setBit calculation TC thing.

class Solution {
public:
    static int findWeight(int num){

        int wt = 0;
        
        while(num>0){
            wt++;
            num&=(num-1);
        }
        return wt;
    }
    static bool cmp(int& a , int& b){
        int setBit1 = findWeight(a);
        int setBit2 = findWeight(b);

        if(setBit1 == setBit2) return a<b;

        return setBit1 < setBit2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};
// same TC and SC

// Without any comparator Function
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end()); 

        map<int, vector<int>> mp;

        for (int x : arr) {
            mp[__builtin_popcount(x)].push_back(x);
        }

        vector<int> ans;
        for (auto &p : mp) {
            for (int el : p.second)
                ans.push_back(el);
        }

        return ans;
    }
};
// TC : O(NlogN)
// SC : O(N)

