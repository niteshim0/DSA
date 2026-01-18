// LC 3814. Maximum Capacity Within Budget
// https://leetcode.com/problems/maximum-capacity-within-budget/description/
// Concept :: PrefixMax + Binary Search + Vector of Pairs + Sorting

// Approach :: For every element at idx i , find the other idx which is in range [0,i-1] such that , costs[i] + other[idx].cost < budget,
// in range search till a particular idx , i want to know what the maximum i can offer in b/w those costs capacity.

// Strikes : 2
// can't figure out it's binary search question
// During Contest :: Solved

class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        
        vector<pair<int,int>> vp;
        int maxi = 0;
        int n = costs.size();
        for(int i = 0;i<n;i++){
            if(costs[i]<budget){
                maxi = max(maxi,capacity[i]);
            }
            vp.emplace_back(costs[i],capacity[i]);
        }

        sort(vp.begin(),vp.end());

        vector<int> prefixMax(n,0);
        prefixMax[0] = vp[0].second;
        for(int i = 1;i<n;i++){
            prefixMax[i] = max(prefixMax[i-1],vp[i].second);
        }

        for(int i = 1;i<n;i++){

            int remainingBudget = budget - vp[i].first - 1; 
            
            if(vp[0].first + vp[i].first>=budget) break ; 
            if(remainingBudget<0) continue;

            int start = 0 , end = i-1 , idx = -1;

            while(start<=end){
                int mid = start + (end-start)/2;
                if(vp[mid].first<=remainingBudget){
                    idx = mid ;
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }

            if(idx!=-1){
                int totalCap = vp[i].second + prefixMax[idx];
                maxi = max(maxi,totalCap);
            } 
        }
        
        return maxi;
    }
};

// Time Complexity : O(N + NlogN + N + NlogN) ~ O(NlogN)
// Space Complexity : O(2*N + N) ~ O(N)
// Optimal Solution :: YES