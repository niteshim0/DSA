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

# Binary Search on 1 D Arrays

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
- [LeetCode 34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
```cpp
class Solution {
public:
    int binarySearch(vector<int>&nums,int target,bool isFirstIdx){
        int n = nums.size();
        int potentialAns = -1;
        int start = 0,end=n-1;

        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]>target){
                end = mid - 1;
            }else if(nums[mid]<target){
                start = mid + 1;
            }else{
                potentialAns = mid;
                if(isFirstIdx){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }
        }
        return potentialAns;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        ans[0] = binarySearch(nums,target,true);
        if(ans[0]!=-1) ans[1] = binarySearch(nums,target,false);
        return ans;

    }
};
```
- [Floor and Ceil in a Sorted Array](https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1)
- [Number of Occurences](https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1)


## Pattern II :: Binary Search in Rotated Sorted Arrays

- [LeetCode 33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // on half will always be sorted be it left or right
        // one other way to find pivot using binarySearch which divides two half
        // and on parted sorted array apply binarySearch
        int n = nums.size();
        int start = 0,end=n-1;
        while(start<=end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target) return mid;

            // left part sorted
            if(nums[start]<=nums[mid]){
                if(nums[start]<=target && target<=nums[mid]){
                    end = mid-1;
                }else{
                    start = mid + 1;
                }
            }else{ // right part sorted
                if(nums[end]>=target && target>=nums[mid]){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
 };
```
This is not going to work if there are duplicates in the array. For that we need to modify the code a bit.Why it doesn't work with duplicates? Because if there are duplicates, we can't decide which part is sorted.Take a case where arr[start] == arr[mid] == arr[end].In this case,it is impossible to decide which part is sorted with our previous approach so we simply eliminate start and end from our search space.In that case, we can just increment the start pointer and decrement the end pointer.

Dry run on this array you will get your answer.
```cpp
[3,1,2,3,3,3,3]
```

- [LeetCode 81. Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0,end=n-1;
        while(start<=end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target) return true;

            // elimating the start pointer and end pointer if its can't let us decide which
            // part is sorted
            if((nums[start] == nums[mid]) && (nums[end] == nums[mid]))
            {
                start++;
                end--;
            }  // left part sorted
            else if(nums[start]<=nums[mid]){
                if(nums[start]<=target && target<nums[mid]){
                    end = mid-1;
                }else{
                    start = mid + 1;
                }
            }else{ // right part sorted
                if(nums[end]>=target && target>nums[mid]){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }

        return false;
    }
};
```

**Complexity Analysis:-** The time complexity of the above approach is O(log n) on average but if there are plenty of duplicated it can go high as close to O(n/2) where n is the number of elements in the array. The space complexity is O(1) as we are using constant space.

- [LeetCode 153. Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
  
- **Approach 1:*
```cpp 
 // I will introduce a new concept here of Pivot Finder which is used to find the pivot in the rotated sorted array . It can be also done by the previous approach but this is more clean and easy to understand(according to me) which also solves all the previous problems as well as the peak type problems.
class Solution {
public:
    int pivotFinder(vector<int>& nums){
        int n = nums.size();
        int start = 0,end=n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(mid<end && nums[mid]>nums[mid+1]){
                return mid;
            }else if(mid>start && nums[mid-1]>nums[mid]){
                return mid-1;
            }else if(nums[start]>=nums[mid]){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        int pivot = pivotFinder(nums);
        return nums[pivot+1];
    }
};
```cpp
**Approach 2:-**
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0,end = n-1;
        int ans = INT_MAX;
        while(start<=end){
            int mid = start + (end-start)/2;

            if(nums[start]<=nums[end]){ // whole portion is sorted
               ans = min(ans,nums[start]);
               break;
            }
            if(nums[start]<=nums[mid]){
               ans = min(ans,nums[start]);
               start = mid + 1;
            }else{
               ans = min(ans,nums[mid]);
               end = mid-1;
            }
        }
        return ans;
    }
};
```

- [LeetCode 154. Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)


```java
//Intuition : Since here number can be duplicated , so we can't decide which part is sorted , we will compare only end and mid and if mid is greater that simply means we can eliminate the left part and if mid is less than end that means we can eliminate the right part(without excluding mid).Try to make a graph and see different cases. // if mid == end we can simply decrement the end pointer.

class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        int start = 0;
        int end = n - 1;
        while(start<end){
            int mid = start + (end-start)/2;
            System.out.println(mid);
            if(nums[mid] > nums[end]){
                start = mid + 1;
            }else if(nums[mid]<nums[end]){
                end = mid;
            }else{
                end--;
            }
        }

        return nums[start];
    }
}
```

## Pattern III :: Peak Element Problems

Learn only one question it almost solves all the peak element problems.In these peak and duplicate type problems always try to draw a graph and see the different cases(almost every case will be visible).
- [LeetCode 162. Find Peak Element](https://leetcode.com/problems/find-peak-element/)
```java
//Intuition : we will check whether our mid is in downward slope or upward slope and if it is in downward slope then we will move to the left side(since peak chances are there) and if it is in upward slope then we will move to the right side(peak chances are there).these are the cases in almost every peak problem.
class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        int start = 1;
        int end = n-2;

        if(n == 1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1; // elimate the corner cases or out of bound error cases

        while(start<=end){
            int mid = start + (end-start)/2;

            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid;
            }else if(nums[mid]>nums[mid+1]){
                end = mid-1;
            }else{
                start = mid + 1;
            }
        }
        return -1;
    }
}
```
- [LeetCode 852. Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/)

## Patter IV : Intuition Based Problems

- [LeetCode 374. Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/)
- [LeetCode 278. First Bad Version](https://leetcode.com/problems/first-bad-version/)
- [LeetCode 540. Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/description/)

```java

// Intuition : Array is sorted only one elment is not repeated , otherwise all element occurs in pairs.
// It gives us a idea to reduce the search space it means the non repeated element makes the count of no odd.
// It also means that all the element occurs on the left side of the non repeated element will have their indices in fashion (even,odd) and all the element occurs on the right side of the non repeated element will have their indices in fashion (odd,even). // this exactly we will use to reduce the search space.
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[n-1]!=nums[n-2]) return nums[n-1];

        int start = 1;
        int end = n-2;

        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }else if (((nums[mid] == nums[mid-1]) && (mid % 2 == 1)) || ((nums[mid] == nums[mid+1]) && (mid % 2 == 0))){
                start = mid + 1;
            }else{
                end = mid-1;
            }
        }
        return -1;
    }
}
```







