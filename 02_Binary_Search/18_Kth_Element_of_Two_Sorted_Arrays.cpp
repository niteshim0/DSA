class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n1 = a.size();
        int n2 = b.size();
        int n = n1 + n2;
        if(n1>n2) return kthElement(b,a,k);
        int start = max(0,k-n2);
        int end = min(k,n1);
        int left = k;
        while(start<=end){
            int mid1 = start + (end-start)/2;
            int mid2 = left-mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if(mid1<n1) r1 = a[mid1];
            if(mid2<n2) r2 = b[mid2];
            if(mid1-1>=0) l1 = a[mid1-1];
            if(mid2-1>=0) l2 = b[mid2-1];
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }else if(l1>r2){
                end = mid1-1;
            }else{
                start = mid1+1;
            }
        }
        return -1;
    }
};

// Time Complexity : O(min(logn1,logn2));
// Space Complexity : O(1)