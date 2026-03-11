// Sum of Subarray Minimums
// https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1

// Concepts :: Monotonic Stack + Aptitude + Subarray Calculation

// Core Idea :: 
/**
For every element arr[i] we find:

-> PSE (Previous Smaller Element) → first index on the left that is smaller.
-> NSE (Next Smaller Element) → first index on the right that is smaller or equal.

Then the element arr[i] will be the minimum for all subarrays that start between  :: (pse[i] + 1)  →  i

and end between :: i  →  (nse[i] - 1) */

// Why > and >= are Different ?
/* 
We use
PSE -> >
NSE -> >=

because of duplicate elements.

Example:
arr = [2,2]
If both sides use >, both 2s try to claim the same subarray [2,2], causing double counting.
Using >= on the right ensures only one element claims duplicate ranges.*/

class Solution {
public:
//   Each element spreads left until a smaller element stops it
// Each element spreads right until a smaller element stops it

    vector<int> nextSmallerElement(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            if(!st.empty()) nse[i] = st.top();

            st.push(i);
        }

        return nse;
    }

    vector<int> prevSmallerElement(vector<int>& arr){
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            if(!st.empty()) pse[i] = st.top();

            st.push(i);
        }

        return pse;
    }

    int sumSubMins(vector<int> &arr) {
        int n = arr.size();

        vector<int> nse = nextSmallerElement(arr);
        vector<int> pse = prevSmallerElement(arr);

        int totalSum = 0;

        for(int i = 0; i < n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;

            totalSum += left * right * arr[i];
        }

        return totalSum;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)

// Technique 2 :: One Pass Solution

class Solution {
public:
    const int MOD = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int totalMinSum = 0;
        stack<int> st;

        for(int i = 0; i <= n; i++) {

            while(!st.empty() && (i == n || arr[st.top()] >= arr[i])) {

                int mid = st.top();
                st.pop();

                int prev = st.empty() ? -1 : st.top();
                int next = i;

                int left = mid - prev;
                int right = next - mid;

                totalMinSum = (totalMinSum + left *1LL* right % MOD * arr[mid] % MOD) % MOD;
            }

            st.push(i);
        }

        return totalMinSum;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)

// Why i == n

// We add a dummy iteration:

// for(i = 0 → n)

// When i == n, we pretend a very small element appeared, forcing the stack to empty and process remaining elements.