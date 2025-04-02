// Selection Sort Ascending Order Version
void selectionSort(vector<int> &arr) {
  int n = arr.size();
  for(int i = 0;i<n-1;i++){
      int mini = i;
      for(int j = i;j<n;j++){
          if(arr[mini]>arr[j]){
              mini = j;
          }
      }
      int temp = arr[i];
      arr[i] = arr[mini];
      arr[mini] = temp;
 }
}

// Average Case = Worst Case = Best Case = O(N*N)
// Space Complexity : O(1)
// Properties of Selection Sort
// It is not stable algorithm (it changes the relative order of elements)
// It is inplace Algorithm
// Selection Sort is best used for small datasets, educational purposes, or when memory usage needs to be minimal.