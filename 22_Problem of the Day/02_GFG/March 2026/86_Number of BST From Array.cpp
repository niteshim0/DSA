// Number of BST From Array
// https://www.geeksforgeeks.org/problems/number-of-bst-from-array/1

// Concepts :: Catalan Numbers + Binary Search + Sorting + Mapping + Hashing

// Approach :: Read about catalan numbers .
// for distinct n numbers -> the number of unique bst that can be formed is catalan[n]
// so for each arr[i] -> the no of unique BST that can be formed is
// cat[left] * cat[right] , where left = no. of elements smaller than arr[i]
// right = no. of elements greater than arr[i]

class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<long long> catalan(n+1, 0);
        catalan[0] = catalan[1] = 1;

        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }


        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        vector<int> ans;

        for(int i = 0; i < n; i++){
            
            int left  = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();
            int right = sorted.end() - upper_bound(sorted.begin(), sorted.end(), arr[i]);

            long long ways = catalan[left] * catalan[right];
            ans.push_back(ways);
        }

        return ans;
    }
};

// Time Complexity : O(N*N)
// Space Complexity : O(N)