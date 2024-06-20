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

# Binary Search on Answers(Predicate Binary Search)

- these questions follow the pattern like (TTTTTFFFFF) or (FFFFTTTT) , at certain point the answer will change from true to false or false to true.i.e at certain limit its potential answer will exist after that it will not exist.

- in such question , we always know what is the range of the answer(we alredy know potential start and end) and we have to find the exact answer in that range(by reducing the search space using binarySearch).(it is one of the most important pattern in binary search).

- we have to only judge starting and ending point of the search space and we have to find the exact answer in that range.

- in such question their is terms like minimum , maximum or their is given some answer range.

-[Square Root of a Number](https://www.geeksforgeeks.org/problems/square-root/0)

```java
//Intuition : we know that square root of a number lies between 1 to n/2(smaller than this also),if we have to do linear search we iterate from 1 to n/2 and check if it is the square root or not. Why can't we do the same using binarySearch(since we alredy know the range of the answer).
// So we will apply binarySearch for every mid value we will check is it the possible square root, if its not is it leads to some smaller value(increase the starting range) or leads to greater than the square root(reduce the end value) and we will reduce the search space accordingly.
class Solution {
    public int mySqrt(int x) {
        int  start = 1 ;
		int end = x;
		
		while(start<=end){
		    int mid = start +(end-start)/2;
		    
		    if(mid == x/mid){
		        return mid;
		    }else if(mid>(x/mid)){
		        end = mid-1;
		    }else{
		        start = mid + 1;
		    }
		}
		return end;
    }
}
```

- [Find Nth root of a number](https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article)
// Same as the previous one , here insted of two times multiplication we will do n times multiplication.

- [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)
// Approach : we will apply binarySearch on the number of hours , for every mid value we will check is it possible to eat all the bananas in that time(mid value) or not , if it is possible then we will reduce the search space to left side(and store the potential answer)(reduce the end) otherwise to the right side(increase the start).
    
```java
class Solution {
    public long feasibleSpeed(long mid,int[] piles){
        long hoursSpent = 0;
        for(int pile  : piles){
            if(pile<=mid){
                hoursSpent++;
            }else{
                long req = pile/mid;
                if(pile%mid!=0){
                    req+=1;
                }
                hoursSpent+=req;
            }
        }
        return hoursSpent;
    }
    public int minEatingSpeed(int[] piles, int h) {
        long start = 1; // the minimum banana he can eat in one hour.
        long end = Arrays.stream(piles).max().getAsInt(); // this is the maximum speed he can eat the bananas even if he eats faster than this answer will not change(since we are taking the ceil value of the division of the pile and mid value).

        long potentialAns = -1;

        while(start<=end){
            long mid = start + (end-start)/2;
            if(feasibleSpeed(mid,piles) <= h){
                potentialAns = mid;
                end = mid-1;
            }else{
                start = mid + 1;
            }
        }
        return (int)potentialAns;
    }
}

```

- [Minimum Number of Days to Make m Bouquets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/)

```java
// Intuition : we will apply binarySearch on the number of days , for every mid value we will check is it possible to make m bouquets in that time(mid value) or not , if it is possible then we will reduce the search space to left side(and store the potential answer)(reduce the end) otherwise to the right side(increase the start).
// Here the main thing to focus on is we need adjacent flowers to make a bouquet.That thing we need to keep in mind while generating the predicate function.

class Solution {
    public int feasibleFlowers(int mid,int k,int[] bloomDay){
        int cnt = 0;
        int bouquetsPossible = 0;
        for(int bloom : bloomDay){
            if(bloom<=mid){
                cnt++;
                if(cnt==k){
                    bouquetsPossible+=1;
                    cnt = 0;
                }
            }else{
                cnt = 0;
            }
        }
        return bouquetsPossible;
    }
    public int minDays(int[] bloomDay, int m, int k) {
        int start = Arrays.stream(bloomDay).min().getAsInt(); // even for 1 bouqet we need at least one flower to bloom.
        int end = Arrays.stream(bloomDay).max().getAsInt(); // the max days after which every flower has bloomed.
        
        int n = bloomDay.length;
        if(m*k>n) return -1; // even after blooming all the flowers they are not so strong in number so that we can make m bouquets.
        int potentialAns = -1;

        while(start<=end){
            int mid = start + (end-start)/2;
            if(feasibleFlowers(mid,k,bloomDay)>=m){
                potentialAns = mid;
                end = mid-1;
            }else{
                start = mid + 1;
            }
        }
        return potentialAns;
    }
}
```

- [Leetcode 1283. Find the Smallest Divisor Given a Threshold](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/) // same as the earlier one do use your brain

- [LeetCode 1011. Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)

```java
// Intuition : we will apply binarySearch on the capacity(mid Value) , for every mid value we will check is it possible to ship all the packages in that time(if the capacity is that then what are the no of days required to ship it)(mid value) or not , if it is possible then we will reduce the search space to left side(and store the potential answer)(reduce the end) otherwise to the right side(increase the start).

// my personal favourite question from whole of binarySearch.

class Solution {
    public int daysRequired(int[] weights,int mid){
        int days = 1;
        int load = 0;
        for(int wt : weights){
            if(load+wt>mid){
                days++;
                load = wt;
            }else{
                load+=wt;
            }
        }

        return days;
    }
    public int shipWithinDays(int[] weights, int days) {
        int start = Arrays.stream(weights).max().getAsInt(); // The minimum capacity to required to ship at least one package.
        int end = Arrays.stream(weights).sum(); // the max capacity which is required to ship all the packages in one day.

        while(start<=end){
            int mid = start + (end-start)/2;
            if(daysRequired(weights,mid)<=days){
                end  = mid - 1;
            }else{
                start = mid +1;
            }
        }
        return start;
    }
}
```

- [Leetcode 1539. Kth Missing Positive Number](https://leetcode.com/problems/kth-missing-positive-number/)
  - the question which is tagged as easy but not so easy even its brute force solution is not so easy to think of and it is an interesting brute force solution.
**Brute Force Solution:-**
  ```java
  class Solution {
    public int findKthPositive(int[] arr, int k) {
        int n = arr.length;
        for(int i = 0;i<n;i++){
            if(arr[i]<=k){
                k++; // if the element is missing then we will increase the k value.
            }else{
                break; // if the element is not missing or it reaches the threshold where their is possibility that element has been found earlier then we will break the loop.
            }
        }

        return k;
    }
}
```

**Binary Search Solution:-**
```java
// Intuition :: For every idx we will check how many elements are missing(it is easy to do so by missing = arr[idx]-(idx+1)) till that idx , if the missing elements are less than k then we will reduce the search space to right side(since it is not possible to exist in left side) otherwise to the left side.

// Here we are not exactly finding the answer but we are finding the shorter search space in which element can exist.For every idx we will check how many elements are missing , then accordingly we will reduce our search space.

//When binary search gets end , the answer is arr[high] +( more which can be added to get to the kth missing element.)

// we need to find that more its comes out to be k - missing.
// and missing here is arr[high] - (high+1) , so the answer is arr[high] + (k - (arr[high]-(high+1)).
// which results in arr[high] + k - arr[high] + high + 1 = k + high + 1.
// high+1 can be also written as low = high+1,
// so the answer is k + low or high + k + 1.(it is the essence of this question)
class Solution {
    public int findKthPositive(int[] arr, int k) {
        int n = arr.length;
        int start = 0;
        int end = n-1;

        while(start<=end){
            int mid = start + (end-start)/2;
            int missing = arr[mid] - (mid+1);
            if(missing<k) start = mid + 1;
            else end = mid - 1;
        }
        return start+k;
    }
}
```
## Binary Search on Answers - Min Max or Max Min Type Problems

- [Aggressive Cows](https://www.geeksforgeeks.org/problems/aggressive-cows/0)
```java
// It is also same as all other predicate type questions , here for every possible distance(1,max-min) between cows , we will find out that it is possible to place that many cows(k) , if it is then we will increas our start = mid + 1(since we need largets minimum distance) , if its not we will reduce our end = mid - 1.

class Solution {
    public static boolean isPossible(int mid,int[] stalls , int k){
        int cowsCount = 1;
        int last = stalls[0];
        int n = stalls.length;
        for(int i = 1;i<n;i++){
            if(stalls[i]-last>=mid){
                cowsCount++;
                last = stalls[i];
                if(cowsCount>=k) return true;
            }else{
                continue;
            }
        }
        
        return cowsCount>=k;
    }
    public static int solve(int n, int k, int[] stalls) {
        Arrays.sort(stalls);
        int maxi = Arrays.stream(stalls).max().getAsInt();
        int mini = Arrays.stream(stalls).min().getAsInt();
        int start = 1;
        int end = maxi - mini;
        
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isPossible(mid,stalls,k)){
                start = mid+1;
            }else{
                end = mid - 1;
            }
        }
        
        return end;
    }
}
```













