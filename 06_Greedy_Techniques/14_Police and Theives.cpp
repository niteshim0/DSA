// https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1
// Police and Thieves
// Concept :: Greedy Approach + Two Pointers


// Approach I :: Brute Force Approach
class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n = arr.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(arr[i] == 'P'){
                int low = max(0,i-k);
                int high = min(i+k,n-1);
            
                for(int j = low;j<=high;j++){
                    if(arr[j] == 'T'){
                        arr[j] = 'L';
                        cnt++;
                        break;
                    }
                }
            }
        }
        
        return cnt;
    }
};
// Time Complexity : O(N*2*K)
// Space Complexity : O(1)
// Verdict :: (TLE for higher n = 1e5 && k = 1e3)

// Approach II :: Greedy Approach
// Try to find the maximum range theives , and if not decrease the distance b/w police and theives

class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        
        int n = arr.size();
        vector<int> police, theives;
        
        for(int i = 0;i<n;i++){
            if(arr[i] == 'P') police.push_back(i);
            else theives.push_back(i);
        }
        
        n = police.size();
        int m = theives.size();
        
        int i = 0 , j = 0, cnt = 0;
        
        while(i<n && j<m){
            if(abs(police[i]-theives[j])<=k){
                cnt++;
                i++;
                j++;
            }else if(police[i]>theives[j]){
                j++; // chor ko pahuchao police ke pass
            }else if(police[i]<theives[j]){
                i++; // police ko thoda tej daudna padega chor ko apne range me laane ke liye
            }
        }
        
        return cnt;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)