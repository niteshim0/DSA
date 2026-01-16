// LC 2975. Maximum Square Area By Removing Fences From a Field
// https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/description/


class Solution {
public:
    const int MOD = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {

        hFences.insert(hFences.end(),{1,m});
        vFences.insert(vFences.end(),{1,n});

        int sz1 = hFences.size() , sz2 = vFences.size();

        unordered_set<int> s1;
        int maxSide = -1;

        for(int i = 0;i<sz1;i++){
            for(int j = i+1;j<sz1;j++){
               int need = abs(hFences[j] - hFences[i]);
               s1.insert(need);
            }
        }

        for(int i = 0;i<sz2;i++){
            for(int j = i+1;j<sz2;j++){
               int need = abs(vFences[j] - vFences[i]);
               if(s1.find(need)!=s1.end()){
                  maxSide = max(maxSide,need);
               }
            }
        }

        return maxSide!=-1 ? (maxSide*1ll*maxSide)%MOD : -1;
    }
};

// Time Complexity : O(((h^2+h)/2) + ((v^2+v)/2))
// Space Complexity : O(((h^2+h)/2))
