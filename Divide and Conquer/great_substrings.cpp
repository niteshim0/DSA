class Solution {
  public:
    long long merge(vector<long long> &arr, int low, int mid, int high) {
        vector<int> temp; 
        int left = low;      
        int right = mid + 1;   

        long long cnt = 0;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                cnt += (mid - left + 1);
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        return cnt;
    }

    long long mergeSort(vector<long long> &arr, int low, int high) {
        long long cnt = 0;
        if (low >= high) return cnt;
        int mid = low + (high - low) / 2; 
        cnt += mergeSort(arr, low, mid);  
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        return cnt;
    }

    long long greatCount(int N, string S) {
        vector<long long> pref(N,0);
        long long sum = 0;
        for(int i = 0;i<N;i++){
            if(S[i] == '0'){
                sum-=1;
            }else{
                sum+=1;
            }
            pref[i] = sum;
        }
        reverse(pref.begin(),pref.end());
        
        long long ans = 0;
        for(auto& x : pref){
            
            if(x>0){
                ans+=1;
            }
        }
        
        ans+=mergeSort(pref,0,N-1);
        return ans;
    }
};