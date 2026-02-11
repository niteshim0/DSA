// Equalize the Towers
// https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1
// Concepts :: Binary Search on Answers


// Approach :: We will check for particualr height , what cost it can incur and choose the minCost , among them


class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
       
       int n = heights.size();
       int start = *min_element(heights.begin(),heights.end());
       int end = *max_element(heights.begin(),heights.end());
       int ans = -1;
       
       
       while(start<=end){
           
           int mid = start + (end-start)/2;
           
           int cost1 = 0;
           int cost2 = 0;
           
           for(int i = 0;i<n;i++){
               cost1+=abs(heights[i]-mid)*cost[i];
               cost2+=abs(heights[i]-(mid+1))*cost[i];
           }
           
           if(cost1<cost2){
               ans = cost1;
               end = mid-1;
           }else{
               start = mid + 1;
           }
           
       }
       
       return ans;
        
    }
};

// Time Complexity : O(logN)
// Space Complexity : O(1)