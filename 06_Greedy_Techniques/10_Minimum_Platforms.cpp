class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        vector<pair<int,char>> vp;
        char ch = 'A';
        for(auto &el : arr){
            vp.push_back({el,ch});
        }
        ch = 'D';
        for(auto &el : dep){
            vp.push_back({el,ch});
        }
        sort(vp.begin(),vp.end());
        int cnt = 0;
        ch = 'A';
        int maxi = 0;
        for(auto &p : vp){
            if(p.second==ch){
                cnt++;
            }else{
               cnt--;
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};
// Time Complexity: O(2Nlog2N + 2N)
// Space Complexity : O(2N)

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int n = arr.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        int maxi = 0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                cnt++;
                i++;
            }else{
                cnt--;
                j++;
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};
// Time Complexity : O(2NlogN + N)
// Space Complexity : O(1)