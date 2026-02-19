// Missing Element in Range
// https://www.geeksforgeeks.org/problems/missing-element-in-range/1
// Concepts :: Hashing + Sorting + Binary Search + Two Pointers


// Approach 1
// Hash the numbers
// traverse from low-> high
// if element not found , add it to your answer

class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
      
      unordered_set<int> st;
      vector<int> res;
      
      for(int &x : arr){
          if(x>=low && x<=high){
              st.insert(x);
          }
      }
      
      
      for(int i = low;i<=high;i++){
          if(st.find(i) == st.end()){
              res.push_back(i);
          }
      }
      
      return res;
        
    }
};
// Time Complexity : O(N + (high-low+1))
// Space Complexity : O(N)

// Approach 2 :: if no auxiliaary space is allowed 
// use sorting + two pointers
// Sort the array
// Move through the range [low, high]
// Skip numbers found in the array

class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
       
       int n = arr.size();
       sort(arr.begin(),arr.end());
       
       int i = 0;
       vector<int> ans;
       
       for(int x = low;x<=high;x++){
           while(i<n && arr[i]<x) i++;
           if(i<n && arr[i] == x) i++;
           else ans.push_back(x);
       }
       
       return ans;
        
    }
};
// Time Complexity : O(NlogN + (high-low+1)) ~ O(NlogN)
// Space Complexity : O(1) or O(N) // sorting takes space
// Sorting is O(1) space if done in-place
// Strictly speaking, in-place quicksort uses O(log n) recursion stack, but in interviews we consider it O(1) auxiliary space since no extra data structures are used.

// Approach 3 :: Binary Search (Optimized for Large Range)
// Sort array
// For each number in [low, high], check presence using binary_search

class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
       
     
       sort(arr.begin(),arr.end());
       
       vector<int> ans;
       
       for(int x = low;x<=high;x++){
          if(!binary_search(arr.begin(),arr.end(),x)){
              ans.push_back(x);
          }
       }
       
       return ans;
        
    }
};

// Time Complexity : O(NlogN + (high-low)(logn)) ~ O((N+high-low)logN))
// Space Complexity : O(1)


// Approach 4 :: Boolean Marking (When range is small)

// Create a boolean array of size (high - low + 1)
// Mark present elements
// Unmarked ones are missing

class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
       
       vector<int> ans;
       vector<int> missing(high-low+1,0);
       
       for(int& x : arr){
           if(x>=low&&x<=high){
               missing[x-low] = 1;
           }
       }
       
       int range = high-low+1;
       
       for(int i = 0;i<range;i++){
           if(missing[i] == 0){
               ans.push_back(low+i);
           }
       }
       
       return ans;
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(high-low+1) // if range is small , highly fast


// Follow Up :: If all the array elements are distinct , and the range also present in the array. What to do ?
// --> Use Cyclic Sort logic
