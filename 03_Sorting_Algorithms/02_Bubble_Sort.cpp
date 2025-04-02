// Bubble Sort(Ascending Order Version)
// Move the maxi to its correct position by adjacent swaps
void bubbleSort(vector<int>& arr) {
  int n = arr.size();
  for(int i = n-1;i>=1;i--){
      bool isSwap = false;
      for(int j = 0;j<i;j++){
          if(arr[j]>arr[j+1]){
              int temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp;
              isSwap = true;
          }
      }
      if(!isSwap) break;
  }
}
// Time Complexity : Average = Worst = O(N*N)
                  // Best  = O(N) (if array is already sorted
// Stable Algorithm
// Space Complexity : O(1)

// Bubble Sort(Descending Order Version)
void bubbleSort(vector<int>& arr) {
  int n = arr.size();
  for(int i = n-1;i>=1;i--){
      bool isSwap = false;
      for(int j = 0;j<i;j++){
          if(arr[j]<arr[j+1]){
              int temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp;
              isSwap = true;
          }
      }
      if(!isSwap) break;
  }
}

