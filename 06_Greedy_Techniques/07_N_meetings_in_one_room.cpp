class Solution {
  public:
    static int cmp(pair<int,int> &a ,pair<int,int> &b){
        return a.second<b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>> vp;
        int n = start.size();
        for(int i = 0 ;i<n;i++){
            vp.push_back({start[i],end[i]});
        }
        sort(vp.begin(),vp.end(),cmp);
        int cnt = 0;
        int ending = -1;
        for(int i = 0;i<n;i++){
            if(vp[i].first>ending){
                ending = vp[i].second;
                cnt++;
            }
        }
        return cnt;
    }
};
// Time Complexity : O(NlogN + 2*N)
// Space Complexity : O(2*N)
