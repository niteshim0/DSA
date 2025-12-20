// LC 944. Delete Columns to Make Sorted
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
         
         int n = strs.size();
         int m = strs[0].size();

         char prev = 'A';
         int cnt = 0;
         
         for(int j = 0;j<m;j++){
            for(int i = 0;i<n;i++){
                if(prev>strs[i][j]){
                    cnt++;
                    break;
                }
                prev = strs[i][j];
            }
            prev = 'A';
        }

        return cnt;
    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(1)