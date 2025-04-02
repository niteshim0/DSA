// 1.Pick a pivot and place it is in its correct position it is supposed to be in sorted array
// 2. Smaller on the leftElements<=pivot<rightElements


class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        if(low<high){
            int partIdx = partition(arr,low,high);
            quickSort(arr,low,partIdx-1);
            quickSort(arr,partIdx+1,high);
        }
    }

  public:
    // Function that takes first element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    void swap(vector<int>& arr,int first,int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
        int i = low;
        int j = high;
        while(i<j){
            while(arr[i]<=pivot && i<=high){
                i++;
            }
            while(arr[j]>pivot && j>=low){
                j--;
            }
            if(i<j){
                swap(arr,i,j);
            }
        }
        swap(arr,low,j);
        return j;
    }
};

// Time Complexity : Average = Best = O(NlogN)
                 // Worst : O(N*N)
// Space Complexity : O(1)

// Desceding Order Version
class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        if(low<high){
            int partIdx = partition(arr,low,high);
            quickSort(arr,low,partIdx-1);
            quickSort(arr,partIdx+1,high);
        }
    }

  public:
    // Function that takes first element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    void swap(vector<int>& arr,int first,int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
        int i = low;
        int j = high;
        while(i<j){
            while(arr[i]>=pivot && i<=high){
                i++;
            }
            while(arr[j]<pivot && j>=low){
                j--;
            }
            if(i<j){
                swap(arr,i,j);
            }
        }
        swap(arr,low,j);
        return j;
    }
};

/*
/ Advantages of Quick Sort
It is a divide-and-conquer algorithm that makes it easier to solve problems.
It is efficient on large data sets.
It has a low overhead, as it only requires a small amount of memory to function.
It is Cache Friendly as we work on the same array to sort and do not copy data to any auxiliary array.
Fastest general purpose algorithm for large data when stability is not required.
It is tail recursive and hence all the tail call optimization can be done.
*/

/*
Disadvantages of Quick Sort
It has a worst-case time complexity of O(n2), which occurs when the pivot is chosen poorly.
It is not a good choice for small data sets.
It is not a stable sort, meaning that if two elements have the same key, their relative order will not be preserved in the sorted output in case of quick sort, because here we are swapping elements according to the pivot’s position (without considering their original positions).
*/

/*
Applications of Quick Sort
Efficient for sorting large datasets with O(n log n) average-case time complexity.
Used in partitioning problems like finding the kth smallest element or dividing arrays by pivot.
Integral to randomized algorithms, offering better performance than deterministic approaches.
Applied in cryptography for generating random permutations and unpredictable encryption keys.
Partitioning step can be parallelized for improved performance in multi-core or distributed systems.
Important in theoretical computer science for analyzing average-case complexity and developing new techniques.
*/

