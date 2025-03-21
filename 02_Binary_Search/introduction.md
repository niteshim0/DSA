## Binary Search
Binary search is a fast search algorithm with run-time complexity of O(log n). This search algorithm works on the principle of divide and conquer. For this algorithm to work properly, the data collection should be in the sorted form.

## Real life applications

1. Binary search can be used as a building block for more complex algorithms used in machine learning, such as algorithms for training neural networks or finding the optimal hyperparameters for a model.
2. It can be used for searching in computer graphics such as algorithms for ray tracing or texture mapping.
3. It can be used for searching a database.(indexing)

## Advantages of Binary Search

1. It is much more efficient than linear search.
2. It is of the order O(log n), which is the best that can be achieved for a search algorithm.
3. Binary search is well-suited for searching large datasets that are stored in external memory, such as on a hard drive or in the cloud.

## Disadvantages of Binary Search

1. The array should be sorted.
2. Binary search requires that the data structure being searched be stored in contiguous memory locations. 
3. Binary search requires that the elements of the array be comparable, meaning that they must be able to be ordered.

## Pseudocode
```
Procedure binary_search
   A ← sorted array
   n ← size of array
   x ← value to be searched

   Set lowerBound = 1
   Set upperBound = n 

   while x not found
      if upperBound < lowerBound 
         EXIT: x does not exists.
   
      set midPoint = lowerBound + ( upperBound - lowerBound ) / 2
      
      if A[midPoint] < x
         set lowerBound = midPoint + 1
         
      if A[midPoint] > x
         set upperBound = midPoint - 1 

      if A[midPoint] = x 
         EXIT: x found at location midPoint
   end while
   
end procedure
```

## Complexity Analysis
- Time complexity: O(log n)
- Space complexity: O(1)

## C++ Iterative Code
```cpp
class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid]>target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return -1;
    }
};
```
## C++ Recursive Code
```cpp
class Solution {
public:
    int binarySearch(vector<int>&nums,int target,int start,int end){
        if(start>end) return -1;
        int mid = start + (end-start)/2;
        if(target==nums[mid]) return mid;
        else if(target>nums[mid]) return binarySearch(nums,target,mid+1,end);
        else return binarySearch(nums,target,start,mid-1);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        return binarySearch(nums,target,start,end);
    }
};
```


