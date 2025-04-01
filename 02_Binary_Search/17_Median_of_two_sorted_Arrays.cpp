// Brute Force Approach
class Solution {
  public:
      double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          int n = nums1.size();
          int m = nums2.size();
          int len = n+m;
          vector<int> arr;
          int i = 0;
          int j = 0;
          while(i<n && j<m){
              if(nums1[i]<nums2[j]){
                  arr.push_back(nums1[i++]);
              }else{
                  arr.push_back(nums2[j++]);
              }
          }
          while(i<n){
             arr.push_back(nums1[i++]);
          }
          while(j<m){
              arr.push_back(nums2[j++]);
          }
          if(len&1) return arr[len/2];
          return double(arr[len/2]+arr[len/2-1])/2.0;
      }
  };
// Time Complexity : O(n+m)
// Space Complexity : O(n+m)

// Better Approach
class Solution {
  public:
      double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          int n = nums1.size();
          int m = nums2.size();
          int k = 0;
          int i = 0;
          int j = 0;
          int len = n+m;
          int first = len/2-1;
          int second = len/2;
          int el1 = -1;
          int el2 = -1;
          while(i<n && j<m){
              if(nums1[i]<nums2[j]){
                  if(k==first) el1 = nums1[i];
                  if(k==second) el2 = nums1[i];
                  i++;
                  k++;
              }else{
                  if(k==first) el1 = nums2[j];
                  if(k==second) el2 = nums2[j];
                  j++;
                  k++;
              }
          }
          while(i<n){
              if(k==first) el1 = nums1[i];
              if(k==second) el2 = nums1[i];
              i++;
              k++;
          }
          while(j<m){
              if(k==first) el1 = nums2[j];
              if(k==second) el2 = nums2[j];
              j++;
              k++;
          }
          if(len&1) return el2;
          return double(el1+el2)/2.0;
  
      }
  };
// Time Complexity : O(N+M)
// Space Complexity : O(1)

// Optimal Approach
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int n1 = nums1.size();
            int n2 = nums2.size();
            int n = n1+n2;
            if(n1>n2) return findMedianSortedArrays(nums2,nums1);//I want to perform binary Search on smaller array for better time complexity
            int start = 0;
            int end = n1;
            int left = (n1+n2+1)/2;
            while(start<=end){
                int mid1 = start + (end-start)/2;
                int mid2 = left-mid1;
                int l1 = INT_MIN;
                int l2 = INT_MIN;
                int r1 = INT_MAX;
                int r2 = INT_MAX;
                // Assigning the left right
                if(mid1<n1) r1 = nums1[mid1];
                if(mid2<n2) r2 = nums2[mid2];
                if(mid1-1>=0) l1 = nums1[mid1-1];
                if(mid2-1>=0) l2 = nums2[mid2-1];
                
                // the correct valid symmetry check
                if(l1<=r2 && l2<=r1){
                    if(n&1) return max(l1,l2);
                    return ((double)(max(l1,l2)+min(r1,r2))/2.0);
                }else if(l1>r2){
                    end = mid1-1;
                }else{
                    start = mid1+1;
                }
            }
            return -1;
        }
    };
//Time Complexity : O(min(logn,logm))
//Space Complexity : O(1)