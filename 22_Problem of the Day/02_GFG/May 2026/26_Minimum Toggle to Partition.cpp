// 26. Minimum Toggle To Partition
// https://www.geeksforgeeks.org/problems/minimum-toogles-to-partition0135/1


// Concept :: Prefix Sum / Suffix Sum 

// Key Idea :: At every idx ,know the violations , that how many elements are violating the required ans condition. (for one know how many one are prefixing that index , for zero know how many zeroes are suffixing that index). these violations we need to toggle for every idx , find the minSum -> that will be required answer.


class Solution {
public:
    int minToggle(vector<int>& arr) {

        int n = arr.size();

        vector<int> prefixOne(n+1,0);
        vector<int> suffixZero(n+1,0);

        for(int i=0;i<n;i++){
            prefixOne[i+1] = prefixOne[i] + (arr[i]==1);
        }

        for(int i=n-1;i>=0;i--){
            suffixZero[i] = suffixZero[i+1] + (arr[i]==0);
        }

        int ans = INT_MAX;

        for(int i=0;i<=n;i++){
            int toggles = prefixOne[i] + suffixZero[i];
            ans = min(ans,toggles);
        }

        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N) -> can be converted to one as well.

class Solution {
public:
    int minToggle(vector<int>& arr) {

        int n = arr.size();

        int oneCnt = accumulate(arr.begin(), arr.end(), 0);
        int zeroCnt = n - oneCnt;

        int ans = INT_MAX;

        int prefixOneCnt = 0;

        for(int i=0;i<=n;i++){

            
            int toggles = prefixOneCnt + zeroCnt;
            ans = min(ans, toggles);

            if(i<n){
                if(arr[i]==1)
                    prefixOneCnt++;
                else
                    zeroCnt--;
            }
        }

        return ans;
    }
};
// SC - O(1)