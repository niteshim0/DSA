# Binary Search

## Need for Binary Search

Binary search is a highly efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing the search interval in half. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise, narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.

## Real-Life Example of Binary Search

A real-life example of binary search is the process of looking up a word in a dictionary. If you open the dictionary in the middle and the word you are looking for comes after the page you are on, you can then look in the middle of the latter half of the dictionary. You repeat this process until you find the word.

## Coding Example

### Iterative Code

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0,end = n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]<target) start = mid + 1;
            else if(nums[mid]>target) end = mid - 1;
            else return mid;
        }
        return -1;
    }
};
```

### Recursive Code

```cpp

class Solution {
public:
    int binarySearch(int start, int end, vector<int>& nums, int target) {
        if (start > end) return -1;
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) return binarySearch(start, mid - 1, nums, target);
        else return binarySearch(mid + 1, end, nums, target);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n - 1;
        return binarySearch(start, end, nums, target);
    }
};

```

## Complexity Analysis

The time complexity of binary search is O(log n) and the space complexity is O(1).

## Important Notes

- Binary search is only applicable in a sorted search space. The sorted search space does not necessarily have to be a sorted array. It can be anything but the search space must be sorted.

- Binary search is a very efficient algorithm and is used in many problems to reduce the time complexity.

- `Sorted Data`: The data must be sorted. Binary search can only be applied to sequences that are ordered.
- `Static Data`: The data should not change frequently. If the data is dynamic and changes often, the overhead of maintaining the sorted order may outweigh the benefits of using binary search.
- `Random Access`: The data structure should support random access (like arrays). Binary search is inefficient for linked lists and other structures that don't allow direct access to the middle element.


