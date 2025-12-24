class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(apple.begin(),apple.end());
        sort(capacity.begin(),capacity.end(),greater<int>());
        
        int i = 0 , j = 0 , n = apple.size() , m = capacity.size() , cnt = 0 , cap = 0;

        while(i<n && j<m){
            if(apple[i]<=cap){
                cap-=apple[i];
                i++;
            }else{
                cnt++;
                cap+=capacity[j];
                j++;
            }
        }

        return cnt;
        
    }
};

// Time Complexity : O(max(n,m)log(max(n,m)))
// Space Complexity : O(n)

// Approach II

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalSum = accumulate(apple.begin(),apple.end(),0);
        sort(capacity.begin(),capacity.end(),greater<int>());
        
        int cap = 0 , i = 0;

        while(totalSum>0){
            totalSum-=capacity[i++];
        }

        return i;
        
    }
};