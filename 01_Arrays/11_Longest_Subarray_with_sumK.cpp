// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399?leftPanelTabValue=PROBLEM

/*1.Brute Force Approach : Generate all the subarrays using two loops.
                           Calculate the maximum one and return it.*/

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int maxi = 0;
    int n = a.size();
    for(int i =0;i<n;i++){
        long long sum = 0;
        for(int j = i;j<n;j++){
            sum+=a[j];
            if(sum==k){
                maxi = max(maxi,(j-i+1));
            }
        }
    }
    return maxi;
}

/*2.Better Approach : Using the concept of x-k + k = x .
                      Using the hashmap.
                      It is optimal if array contains positive , negative and zeroes.*/
                    #include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> arr, long long k) {
    // Write your code here
     unordered_map<long long,int> mp;
        int n = arr.size();
        long long sum = 0;
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            sum+=arr[i];
            long long remsum = sum-k;
            if(sum==k){
                maxi = max(maxi,i+1);
            }
            if(mp.find(remsum)!=mp.end()){
                int len = i-mp[remsum];
                maxi = max(maxi,len);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum] = i;
            }
        }
        return maxi == INT_MIN ? 0 : maxi;
}

/*3.Optimal Approach(applicable only if array contains only positives) : Use the sliding window approach.*/

int longestSubarrayWithSumK(vector<int> arr, long long k) {
  int left = 0;
  int right = 0;
  long long sum = arr[0];
  int n = arr.size();
  int maxi = 1;
  while(right<n){
      while(left<=right && sum>k){
          sum-=arr[left];
          left++;
      }
      if(sum == k){
          maxi = max(maxi,right-left+1);
      }
      if(right<n){
          right++;
          sum+=arr[right];
      }
  }
  return maxi;
}