// Brute Force Approach

void swap(vector<int>& nums,int first, int second){
        int temp  = nums[first];
        nums[first] = nums[second];
        nums[second] = temp;
    }
    void generatePermute(int idx,vector<int>&nums,vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = idx;i<nums.size();i++){
            swap(nums,i,idx);
            generatePermute(idx+1,nums,ans);
            swap(nums,i,idx);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        generatePermute(0,nums,ans);
        return ans;
    }
## 🧠 Time and Space Complexity

### ✅ Time Complexity: `O(n! × n)`
- `O(n!)` → Total number of permutations of `n` elements.
- Each permutation takes `O(n)` time to construct.
- Sorting all `n!` permutations takes `O(n! × n log n)` additionally.
- Accessing the `k-th` permutation is `O(n)`.

➡️ Overall time complexity: **O(n! × n + n! × n log n)**

### ✅ Space Complexity: `O(n! × n)`
- To store all permutations in a 2D vector.
- Auxiliary recursion stack space is `O(n)` for backtracking.

➡️ Dominated by storage of permutations: **O(n! × n)**

// Optimal Approach

class Solution {
public:
    string getPermutation(int n, int k) {
        long long fact = 1;
        vector<int> nums;
        
        // Prepare factorial and number list
        for (int i = 1; i < n; i++) {
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);

        k--;  // zero-based index
        string ans = "";

        while (!nums.empty()) {
            int index = k / fact;
            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);

            if (nums.empty()) break;

            k %= fact;
            fact /= nums.size();
        }
        return ans;
    }
};

## Time and Space Complexity

### ✅ Time Complexity: `O(n²)`
- The main cost comes from `nums.erase(nums.begin() + index)` inside a loop that runs `n` times.
- Each erase operation in a vector takes `O(n)` in the worst case (shifting elements).
- Total complexity: `O(n) × O(n) = O(n²)`.

### ✅ Space Complexity: `O(n)`
- The `nums` vector stores numbers from `1` to `n`.
- The factorial variable and other constants use `O(1)` space.
- The output string `ans` uses `O(n)` space.
