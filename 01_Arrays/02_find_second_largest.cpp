/* https://www.geeksforgeeks.org/problems/second-largest3735/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card/ */
//Find second largest element in an Array

/*Brute Force : - Sort the array
                - Take the last index element as largest 
                - Traverse the array from n-2 index in reverse order.
                - The element which is arr[i]!=largest will be ans. */

int findSecondLargest(vector<int>& v){
  int n = v.size();
  if(n<2) return -1;
  sort(v.begin(),v.end());
  int largest = v[n-1];
  for(int i = n-2;i>=0;i--){
        if(v[i]!=largest){
          return v[i];
        }
  }
  return -1;
}

/*Better Approach : - Iterate the array once to find largest.
                    - Iterate the second time to find element such that arr[i]!=largest and still     greater than all the other elements.*/

int getSecondLargest(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int largest = arr[0];
        for(int i = 0;i<n;i++){
            if(arr[i]>largest){
                largest = arr[i];
            }
        }
        int secondLargest = INT_MIN;
        bool didWeFind = false; //to handle the duplicate cases
        for(int i = 0;i<n;i++){
            if(arr[i]!=largest && arr[i]>secondLargest){
                secondLargest = arr[i];
                didWeFind = true;
            }
        }
        return didWeFind ? secondLargest : -1;
}

/*Optimal Approach : - Iterate the array 
                     - If there is need to update largest then that largest becomes secondLargest.
                     - If there is an element such that arr[i]<largest and arr[i]>secondLargest,update it.*/

int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int largest = arr[0];
        int secondLargest = -1;
        for(int i = 0;i<n;i++){
            if(arr[i]>largest){
                secondLargest = largest;
                largest = arr[i];
            }else if(arr[i]<largest && arr[i]>secondLargest){
                secondLargest = arr[i];
            }
        }
        return secondLargest;
}

