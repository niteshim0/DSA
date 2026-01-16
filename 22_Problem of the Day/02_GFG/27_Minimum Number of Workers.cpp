// Minimum Number of Workers
// https://www.geeksforgeeks.org/problems/minimum-sprinklers/1
// Concept :: Intervals + Greedy + Sorting
// Approach :: For every element , decides its what range it can cover,
// and then sort it accordingly leftone , so that we knew which one goes the farthest and minimum is covered by our sorting earlier , if it goes till n-1 , all well and good , if not -> return -1

class Solution {
  public:
    int minMen(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<pair<int,int>> vp;
        
        for(int i = 0;i<n;i++){
            if(arr[i]!=-1){
    
                int leftRange = max(i-arr[i],0);
                int rightRange = min(i+arr[i],n-1);
                vp.push_back({leftRange,rightRange});
            }
        }
        
        sort(vp.begin(),vp.end());
        
        int m = vp.size();
        
        int covered = -1 , i = 0;
        int farthest = -1,people = 0;
        
        while(covered<n-1){
            
            farthest = covered;
            
            while(i<m && vp[i].first<=covered+1){
               farthest = max(farthest,vp[i].second);
               i++;
            }
            
            if(farthest == covered) return -1;
            
            people++;
            covered = farthest;
        }
        
        return people;
    }
};

// Time Complexity : O(n(first iteration) + mlogm(sorting purpose) + O(N+M)) ~ O(MlogM)
// Space Complexity : (M) // for storing purposes + O(M) // for stack space during sorting ~ O(M)