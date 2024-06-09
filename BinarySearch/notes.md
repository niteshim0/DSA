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

## Pattern I :: lower_bound and upper_bound

**lower_bound**: In a sorted sequence of elements, the lower_bound function returns an iterator pointing to the first element that is not less than a specified value. If there are multiple elements with the same value as the specified one, lower_bound points to the first occurrence of such value.

```cpp
int lower_bound(vector<int>& arr, int target) {
    int n = arr.size();
    int potentialIdx = n;
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= target) {
            potentialIdx = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return potentialIdx;
}
```

**upper_bound**: In a sorted sequence of elements, the upper_bound function returns an iterator pointing to the first element that is greater than a specified value. If there are multiple elements with the same value as the specified one, upper_bound points to the first element following the specified value.

```cpp
int upper_bound(vector<int>& arr, int target) {
    int n = arr.size();
    int potentialIdx = n;
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] >target) {
            potentialIdx = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return potentialIdx;
}
```

**Different Available Functions in Different Programming Languages**

- In C++: lower_bound, upper_bound
In C++ STL, you can use the functions std::lower_bound and std::upper_bound to find the lower-bound and upper-bound respectively in various data structures like vectors, arrays, etc.

```cpp
int main() {
    std::vector<int> vec = {1, 2, 2, 3, 4, 4, 5};
    int target = 3;

    auto lower = std::lower_bound(vec.begin(), vec.end(), target);
    auto upper = std::upper_bound(vec.begin(), vec.end(), target);

    int lowerIndex = lower - vec.begin();
    int upperIndex = upper - vec.begin();
    // Now lowerIndex is the index of the first element not less than target
    // and upperIndex is the index of the first element greater than target
    return 0;
}
```
- In Python: bisect_left, bisect_right
In Python, you can use the functions bisect_left and bisect_right from the bisect module to find the lower-bound and upper-bound respectively in a sorted list.

```python
import bisect
arr = [1, 2, 2, 3, 4, 4, 5]
target = 3

lower = bisect.bisect_left(arr, target)
upper = bisect.bisect_right(arr, target)

# Now lower is the index of the first element not less than target
# and upper is the index of the first element greater than target
```

- In Java: Arrays.binarySearch
In Java, you can use the Arrays.binarySearch method to find the index of the first occurrence of an element in a sorted array. If the element is not found, it returns a negative value.

```java
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] arr = {1, 2, 2, 3, 4, 4, 5};
        int target = 3;

        int lower = Arrays.binarySearch(arr, target);
        int upper = Arrays.binarySearch(arr, target + 1);

        // Now lower is the index of the first element not less than target
        // and upper is the index of the first element greater than target
    }
}
```

**Complexity Analysis:-**
The time complexity of lower_bound and upper_bound is O(log n) where n is the number of elements in the sequence. The space complexity is O(1) as we are using constant space.

**Applications:-**
- lower_bound and upper_bound are widely used in competitive programming to solve problems that require finding the first element not less than or greater than a target value in a sorted sequence.
- They are used in problems that require finding the number of occurrences of a target value in a sorted sequence.
- They are used in problems that require finding the range of indices containing a target value in a sorted sequence.

**Questions:-**
- [LeetCode 35. Search Insert Position](https://leetcode.com/problems/search-insert-position/)




