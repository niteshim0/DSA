// Find H-Index
// https://www.geeksforgeeks.org/problems/find-h-index--165609/1
// Concepts :: Sorting + Arrays
/*
If the citations are sorted, then at any index i, the number of papers that have citations ≥ citations[i] is (n - i).
So we just need to check:
“Are there (n - i) papers with at least (n - i) citations?”
If yes, then (n - i) can be an H-index.
*/
class Solution {
  public:
    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(),citations.end());
        
        int n = citations.size();
        
        for(int i = 0;i<n;i++){
            if((n-i)<=citations[i]){
                return n-i;
            }
        }
        
        return 0;
        
    }
};

// Time Complexity : O(NlogN)
// Space Complexity : O(1)