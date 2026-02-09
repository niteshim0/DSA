// Find Kth Rotation
// https://www.geeksforgeeks.org/problems/rotation4723/1
// Concept :: Linear Search  + Binary Search


// Approach :: We have to find that idx from where we decrease , and decreseIdx + 1 is no of times of rotation


// Technique 1 :: Linear Search

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int ans = -1;
        for(int i = 1;i<n;i++){
            if(arr[i-1]>arr[i]){
                ans = i-1;
                break;
            }
        }
        
        return ans == -1 ? 0 : ans+1;
        
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)

// Technique 2 :: Binary Search

class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int start = 0, end = n - 1;

        while (start <= end) {
            if (arr[start] <= arr[end])
                return start; 

            int mid = start + (end - start) / 2;

            if (mid > 0 && arr[mid] < arr[mid - 1])
                return mid;

            if (arr[mid] >= arr[start])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return 0;
    }
};

// Time Complexity : O(logN)
// Space Complexity : O(1)