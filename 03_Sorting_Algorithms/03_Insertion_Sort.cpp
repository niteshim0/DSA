// Insertion Sort(Ascending Order Version)
// Take an Element and place it is in correct position
void insertionSort(vector<int>& arr) {
  int n = arr.size();
  for(int i = 0;i<n;i++){
      int j = i;
      while(j>0 && arr[j-1]>arr[j]){
          int temp = arr[j];
          arr[j] = arr[j-1];
          arr[j-1] = temp;
          j--;
      }
  }
}
// Time Complexity : Average = Worst = O(N*N)
                  // Best  = O(N)
// Stable Algorithm
// Space Complexity : O(1)
/*
Simple and easy to implement.
Stable sorting algorithm.
Efficient for small lists and nearly sorted lists.
Space-efficient as it is an in-place algorithm.
Adoptive. the number of inversions is directly proportional to number of swaps. For example, no swapping happens for a sorted array and it takes O(n) time only
*/

// Insertion Sort(Descending Order Version)
void insertionSort(vector<int>& arr) {
  int n = arr.size();
  for(int i = 0;i<n;i++){
      int j = i;
      while(j>0 && arr[j-1]<arr[j]){
          int temp = arr[j];
          arr[j] = arr[j-1];
          arr[j-1] = temp;
          j--;
      }
  }
}