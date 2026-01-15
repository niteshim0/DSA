// Candy
// https://www.geeksforgeeks.org/problems/candy/1
// Concept :: Peak and Valley
// Approach :: If we are moving towards peak increase every peak than its previous ones. Do same thing from both sides(left,right) -> and choose the maximum one among these.


class Solution {
  public:
    int minCandy(vector<int> &arr) {
        
        int n = arr.size();
        vector<int> left(n,1) , right(n,1);
        
        for(int i = 1;i<n;i++){
            if(arr[i-1]<arr[i]){
                left[i] = left[i-1] + 1;
            }
        }
        
        for(int i = n-2;i>=0;i--){
            if(arr[i+1]<arr[i]){
                right[i] = right[i+1] + 1;
            }
        }
        
        int ans = 0;
        
        for(int i = 0;i<n;i++){
            ans+=max(left[i],right[i]);
        }
        
        return ans;
    }
};

// Time Complexity : O(N+N+N == 3N) ~ O(N) // for looping purposes
// Space Complexity : O(N+N == 2N) ~ O(N)  // for storing peak purposes 