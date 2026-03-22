// LC 3878. Count Good Subarrays
// https://leetcode.com/problems/count-good-subarrays/description/

// Concepts :: BitwiseOR + Monotonic Array + Mapping + Hashing


class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        // Tracks the most recent index where each number appeared as an element
        unordered_map<int, int> lastSeen;
        
        // Tracks the starting index 'j' for each unique OR value ending at current 'i'
        // Format: {OR_value -> earliest_j}
        unordered_map<int, int> prevORs; 

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> currORs;
            
            // Update last seen position of the current element
            lastSeen[nums[i]] = i;

            // Base case: Subarray of length 1 starting and ending at i
            currORs[nums[i]] = i;

            // Expand previous OR results with the current element
            for (auto& [val, startIdx] : prevORs) {
                int newOR = val | nums[i];
                if (currORs.find(newOR) == currORs.end()) {
                    currORs[newOR] = startIdx;
                } else {
                    // Keep the smallest index to cover the maximum range of subarrays
                    currORs[newOR] = min(currORs[newOR], startIdx);
                }
            }

            // Logic: A subarray [j...i] is "good" if OR(j...i) exists in [j...i]
            // We iterate through all unique OR values ending at index i
            for (auto& [currentOR, start] : currORs) {
                // Check if currentOR was seen as an actual element in the array
                if (lastSeen.count(currentOR)) {
                    int pos = lastSeen[currentOR];
                    
                    // We need to find how many 'j' in [start, i] satisfy:
                    // 1. The OR of [j...i] is exactly 'currentOR'
                    // 2. The element 'currentOR' is present in [j...i]
                    
                    // Finding the boundary: 
                    // 'start' is the earliest j where OR is currentOR.
                    // 'pos' is the latest index where currentOR appeared as an element.
                    // If pos >= start, then for all j in [start, pos], 
                    // the subarray [j...i] contains the element 'currentOR'.
                    
                    // Note: We must also ensure we don't overcount if this OR 
                    // value overlaps with another range (handled by the map structure).
                    
                    // To get the exact count for this OR value's specific range:
                    // Find the 'next' OR value's start index to define the end of this interval
                    int endOfJRange = i; 
                    for (auto& [otherOR, otherStart] : currORs) {
                        if (otherStart > start) {
                            endOfJRange = min(endOfJRange, otherStart - 1);
                        }
                    }

                    int validJEnd = min(endOfJRange, pos);
                    if (validJEnd >= start) {
                        ans += (validJEnd - start + 1);
                    }
                }
            }
            prevORs = currORs;
        }

        return ans;
    }
};

// Time Complexity : O(N*31)
// Space Complexity : O(N+N+N)