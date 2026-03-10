// Subarrays with First Element Minimum
// https://www.geeksforgeeks.org/problems/subarrays-with-first-element-minimum/1
// Concept :: Monotonic Stack

// Approach :: For each index, we will keep track of nextSmallerElement index , in this way , the subarray where i will be minimum is [i,nextSmallerElement idx) , i.e. from i before nextSmallerElement idx.(that range will constitue the minimum subarray range (add them to ans+=(nextSmallerElemeentIdx-i)))


// Technique I : With Extra Array

class Solution {
public:

    vector<int> nextSmallerIndex(vector<int>& arr){
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

    int countSubarrays(vector<int> &arr) {
        int n = arr.size();
        vector<int> nse = nextSmallerIndex(arr);

        int ans = 0;

        for(int i = 0; i < n; i++){
            ans += (nse[i] - i);
        }

        return ans;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)

// Technique 2 :: Without Extra Array
class Solution {
public:

    vector<int> nextSmallerIndex(vector<int>& arr){
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

    int countSubarrays(vector<int> &arr) {
        int n = arr.size();
        vector<int> nse = nextSmallerIndex(arr);

        int ans = 0;

        for(int i = 0; i < n; i++){
            ans += (nse[i] - i);
        }

        return ans;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)