class Solution {
  public:
    bool isPossible(vector<int>&stalls,int mid,int k){
        int cows = 1;
        int prev = stalls[0];
        int n = stalls.size();
        for(int i = 1;i<n;i++){
            if(stalls[i]-prev>=mid){
                cows++;
                prev = stalls[i];
                if(cows>=k) return true;
            }
        }
        return cows>=k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int n = stalls.size();
        if(k>n) return -1;
        int maxi = stalls[n-1];
        int mini = stalls[0];
        int start = 1;
        int end = maxi-mini;
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isPossible(stalls,mid,k)){
                ans = mid;
                start = mid+1;
            }else{
                end = mid-1; 
            }
        }
        return ans;
    }
};