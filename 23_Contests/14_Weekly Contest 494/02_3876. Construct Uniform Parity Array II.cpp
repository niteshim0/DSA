// LC 3876. Construct Uniform Parity Array II
// https://leetcode.com/problems/construct-uniform-parity-array-ii/description/

// Concepts :: Parity + Sorting

// Approach :: Since because of this constraint 
//nums2[i] = nums1[i] - nums1[j], for an index j != i, such that nums1[i] - nums1[j] >= 1
// i.e difference should be some positive number 
// -> nothing can be subtracted from the smallest element -> so it will remain as it is , so its parity will be deciding factor i.e whatever parity of the minimum element in array is , that will be final parity of all modified or non-modified elements in ans array.
// i.e. if targetParity == 0 , and even one element exist wholse parity is not equal to targetParity -> return false;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int mini = *min_element(nums1.begin(),nums1.end());

        int targetParity = mini%2;

        if(targetParity == 0){

            for(int &x : nums1){

                if(x%2!=0) return false;
            }
        }

        return true;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)