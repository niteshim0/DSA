// Divide the array into 2 parts and merge the sorted parts and make it reflect on original array
class Solution {
  public:
    void merge(vector<int>& arr,int start,int mid,int end){
        vector<int> temp;
        int left = start;
        int right = mid+1;
        while(left<=mid && right<=end){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=end){
            temp.push_back(arr[right]);
            right++;
        }
        
        // reflecting this merge into original array;
        for(int i = start;i<=end;i++){
            arr[i] = temp[i-start];
        }
    }
    void mergeSort(vector<int>& arr, int start, int end) {
        if(start>=end) return;
        int mid = start + (end-start)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
};

// Time Complexity : O(NlogN) O(N)-For Merge and LogN time Merge happens
// Space Complexity : O(N)

/* Recurrence Relation : {
O(1) if n = 1
2T(n/2) + O(n) , if n>1
} */

/* Applications of Merge Sort
Sorting large datasets
External sorting (when the dataset is too large to fit in memory)
Inversion counting
Merge Sort and its variations are used in library methods of programming languages.
Its variation TimSort is used in Python, Java Android and Swift. The main reason why it is preferred to sort non-primitive types is stability which is not there in QuickSort.
Arrays.sort in Java uses QuickSort while Collections.sort uses MergeSort.
It is a preferred algorithm for sorting Linked lists.
It can be easily parallelized as we can independently sort subarrays and then merge.
The merge function of merge sort to efficiently solve the problems like union and intersection of two sorted arrays.
*/

/*Advantages of Merge Sort
Stability : Merge sort is a stable sorting algorithm, which means it maintains the relative order of equal elements in the input array.
Guaranteed worst-case performance: Merge sort has a worst-case time complexity of O(N logN) , which means it performs well even on large datasets.
Simple to implement: The divide-and-conquer approach is straightforward.
Naturally Parallel : We independently merge subarrays that makes it suitable for parallel processing.
*/

/*Disadvantages of Merge Sort
Space complexity: Merge sort requires additional memory to store the merged sub-arrays during the sorting process.
Not in-place: Merge sort is not an in-place sorting algorithm, which means it requires additional memory to store the sorted data. This can be a disadvantage in applications where memory usage is a concern.
Merge Sort is Slower than QuickSort in general as QuickSort is more cache friendly because it works in-place.
*/


// Descending Order Version
class Solution {
  public:
    void merge(vector<int>& arr,int start,int mid,int end){
        vector<int> temp;
        int left = start;
        int right = mid+1;
        while(left<=mid && right<=end){
            if(arr[left]>=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=end){
            temp.push_back(arr[right]);
            right++;
        }
        
        // reflecting this merge into original array;
        for(int i = start;i<=end;i++){
            arr[i] = temp[i-start];
        }
    }
    void mergeSort(vector<int>& arr, int start, int end) {
        if(start>=end) return;
        int mid = start + (end-start)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
};