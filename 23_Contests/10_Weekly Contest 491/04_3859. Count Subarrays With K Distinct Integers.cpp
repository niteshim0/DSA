// 3859. Count Subarrays With K Distinct Integers
// https://leetcode.com/problems/count-subarrays-with-k-distinct-integers/description/

// Concepts :: Sliding Window + Hashing + Boundary Check Conditions + Counting Valid things in a Range + Shrinking

// Intuition :: Maintain a sliding window with exactly k distinct numbers, track when each reaches m occurrences, and trim extra duplicates from the left to count multiple valid starting positions.

// Approach :: If there are exactly k distinct numbers and each appears ≥ m times, then the number of elements that have frequency ≥ m must also be exactly k.

// This leads to tracking two things:
// 1. distinct → number of distinct elements in the window
// 2. good → number of elements whose frequency reached m
// ==> When distinct == k and good == k, every element appears at least m times.



class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        unordered_map<int,int> freq;

        int n = nums.size();
        long long ans = 0;

        int left = 0;
        int validStart = 0;
        int distinct = 0;
        int good = 0;

        for(int right = 0; right < n; right++) {

            freq[nums[right]]++;

            if(freq[nums[right]] == 1) distinct++;
            if(freq[nums[right]] == m) good++;

            while(distinct > k) {
                if(freq[nums[left]] == m) good--;

                freq[nums[left]]--;

                if(freq[nums[left]] == 0) distinct--;

                left++;
                validStart = left;
            }

            while(distinct == k && good == k && freq[nums[validStart]] > m) {
                freq[nums[validStart]]--;
                validStart++;
            }

            if(distinct == k && good == k)
                ans += validStart - left + 1;
        }

        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)

