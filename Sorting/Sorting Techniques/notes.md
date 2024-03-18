# Sorting Algorithms

## Selection Sort

- It  is an algorithm which in every pass selects an element from entire array/lists and puts its on its correct index position(the index it will have when array has been sorted).
- It is not stable.( Stable sorting algorithms maintain the relative order of equal elements).
- It peforms well on small list,not suitable for large data sets.
- Comparison based sorting algorithm.
- In-place sorting algorithm.
- Adaptive: Selection Sort is not adaptive. The time taken to sort the list remains the same regardless of whether the list is partially sorted or completely unsorted.

**Code**
```java
static void selection(int[] arr){
  int n = arr.length;
  for(int i = 0;i<n;i++){
    int lastIdx = n-i-1;
    int maxIdx = getMaxIndex(arr,0,lastIdx); //it could be minimum as your wish
    swap(arr,maxIdx,lastIdx);
  }
}
static void swap(int[] arr,int first,int second){
  int temp = arr[first];
  arr[first] = arr[second];
  arr[second] = temp;
}
static int getMaxIndex(int[] arr,int start,int end){
  int maxIdx = start;
  for(int i = start;i<=end;i++){
    if(arr[maxIdx]<arr[i]){
      maxIdx = i;
    }
  }
  return maxIdx;
}
```
**Time Complexity**
- Best Case : O(N^2)
- Worst Case : O(N^2)

**Space Complexity**
- O(1)

**Problem Link**
- [Selection Sort](https://www.codingninjas.com/studio/problems/selection-sort_624469)

## Bubble Sort // Exhange Sort // Sinking Sort

- Bubble Sort is renowned as one of the simplest sorting algorithms. It operates by iteratively traversing the list and comparing adjacent elements. If they are in the wrong order, it swaps them. This process is repeated until the list is completely sorted. At each comparison, Bubble Sort decides whether a swap is necessary to correct the order. 
- The algorithm gets its name from the way smaller elements "bubble" to the top (beginning) of the list in each pass.
- It is stable sorting alogrithm.
- In-place sorting alogrithm.
- It is comparison based algorithm.
- Efficient on small dataset, not suitable for large datasets.
- Adaptive: Bubble Sort is not adaptive. The time taken to sort the list remains the same regardless of whether the list is partially sorted or completely unsorted.

**Code**
```java
//Ascending Order Implementation
static void bubble(int[] arr){
  boolean swapped;
  int n = arr.length;
  for(int i = 0;i<n;i++){
      swapped = false;
      for(int j = 1;j<n-i;j++){
        if(arr[j]<arr[j-1]){
          int temp = arr[j];
          arr[j] = arr[j-1];
          arr[j-1] = temp;
          swapped = true;
        }
      }
      if(!swapped){
        //Array is sorted now,come out of the loop
        break;
      }
  }
}
```

**Time Complexity**
- Best Case : O(N) (Array is sorted in same manner as required)
- Worst Case : O(N^2)(Array is sorted in opposite manner as required)
- Average Case : O(N^2)

**Space Complexity**
 - O(1)

**Problem Link**
- [Bubble Sort](https://www.codingninjas.com/studio/problems/bubble-sort_624380)

## Insertion Sort

- It is a sorting algorithm which makes the array paritally sorted with every pass.
- A stable sorting algorithm.
- In-place sorting alogrithm.
- It is comparison based algorithm.
- Efficient on small dataset, not suitable for large datasets.
- Adaptive: Insertion Sort is adaptive. It performs better when the input list is partially sorted or nearly sorted because it reduces the number of comparisons and swaps required.
- Efficient for Small Datasets and Nearly Sorted Lists,Not Suitable for Large Datasets.
- It also takes part in hybrid sorting algorithms(takes part in inbuilt sort function of programming languages.)

**Code**
```java
static void insertion(int[] arr){
  int n = arr.length;
  for(int i = 0;i<n-1;i++){
    for(int j = i+1;j>0;j--){
      if(arr[j]<arr[j-1]){
        swap(arr,j,j-1);
      }else{
        break; // it must be sorted for that pass , no need to get ahead
      }
    }
  }
}
static void swap(int[] arr,int first,int second){
  int temp = arr[first];
  arr[first] = arr[second];
  arr[second] = temp;
}
```

**Time Complexity**
- Best Case : O(N) (Array is sorted in same manner as required)
- Worst Case : O(N^2)(Array is sorted in opposite manner as required)
- Average Case : O(N^2)

**Space Complexity**
- O(1)

**Problem Link**
- [Insertion Sort](https://www.codingninjas.com/studio/problems/insertion-sort_624381)

## Cyclic Sort

- Cyclic sort is an efficient in-place sorting algorithm primarily used when dealing with arrays containing a distinct range of integers.

- Cyclic sort is` not a stable` sorting algorithm, meaning it does not necessarily preserve the order of equal elements.

- `In-place Sorting`: The sorting is performed within the given array without requiring additional memory allocation proportional to the size of the input.

- `Comparison-free`: Unlike comparison-based sorting algorithms like Quicksort or Merge sort, Cyclic sort does not directly compare elements to each other during the sorting process. Instead, it relies on the cyclic nature of the permutation.

- `Suitable for Restricted Range`: Cyclic sort is most efficient when dealing with arrays where the elements are integers within a specific range, typically from 1 to n, where n is the size of the array.The most important property of it , for only this reason it gets heavily asked intervies.

- `Adaptability`: Cyclic sort is particularly useful when memory is a concern or when the range of values in the array is known and small.

- `Deterministic`: The behavior of cyclic sort is deterministic, meaning that given the same input, it will always produce the same output.

**Code**
```c++
   void swap(vector<int>&arr,int first,int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
    void cyclicSort(vector<int>&arr){
        int i = 0;
        int n = arr.size();
        while(i<n){
            int correctIdx = arr[i];
            if(correctIdx == n){
                i++;
            }else if(arr[i]!=arr[correctIdx] && correctIdx!=n){
                swap(arr,i,correctIdx);
            }else{
                i++;
            }
        }
    }
```

**Time Complexity**
- O(1)

**Space Complexity**
- O(1)

**Problem Link**
- [Missing Number](https://leetcode.com/problems/missing-number/)
















