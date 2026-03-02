// Trapping Rain Water
// https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
// Concepts :: Prefix and Suffix Array Concept + Mental Mathematics + Two Pointer + General Aptitude

// Approach I :: Prefix and Suffix Max Tracker Concept 
// For every idx , we need to know which is the max building possible either from left side as well as right side , and between these two we have to choose , min one , uske upar ka to paani gir jayega (that's the whole logic , whether even you go for two pointer way)


class Solution {
  public:
    int maxWater(vector<int> &arr) {
        
        // Approach I :: Prefix and Suffix Array Concept ,
        int n = arr.size();
        vector<int> prefixMax(n,0) , suffixMax(n,0);
        int maxi1 = INT_MIN , maxi2 = INT_MIN;
        
        for(int i = 0;i<n;i++){
            
            maxi1 = max(maxi1,arr[i]);
            prefixMax[i] = maxi1;
            
            maxi2 = max(maxi2,arr[n-i-1]);
            suffixMax[n-i-1] = maxi2;
        }
        
        int ans = 0;
        
        for(int i = 0;i<n;i++){
            
            int minHeight = min(prefixMax[i],suffixMax[i]);
            ans+=(minHeight-arr[i]);
        }
        
        return ans;
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)


// Approach II : Two Pointer Technique

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        
        // Approach II :: Two Pointer Technique
        int n = arr.size();
        int left = 0  , right = n-1;
        int leftMax = INT_MIN  , rightMax = INT_MIN;
        
        int ans = 0;
        
        while(left < right){
            
            if(arr[left]<=arr[right]){
                leftMax = max(leftMax,arr[left]);
                ans+=(leftMax-arr[left]);
                left++;
            }else{
                rightMax = max(rightMax,arr[right]);
                ans+=(rightMax-arr[right]);
                right--;
            }
        }
        
        return ans;
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)