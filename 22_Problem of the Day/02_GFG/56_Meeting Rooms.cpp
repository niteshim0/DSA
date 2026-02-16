// Meeting Rooms
// https://www.geeksforgeeks.org/problems/attend-all-meetings/1
// Concepts :: Sorting + Comparator + Interval Question


// Approach :: There is only one person , and he need to attend all the meetings , in one case he will not be able to attend all , if any two meetings have time overlap , that's exactly what we will check , since if we check each to other -> that will easily take O(n^2) time , we will avoid that , rather it is clear that , person can go to other meeting , if firstOne ends , so we will sort the meetings by its end time , and check adjacent intervals , if they overlap , then he can't attend both --> return false , if this case doesn't arises while going through all the intervals he is able to attend all the meetings (think about his mental work-balance) --> return true.

class Solution {
  public:
    static bool cmp(vector<int>& first,vector<int>& second){
        if(first[1] == second[1]) return first[0]<=second[0];
        return first[1]<second[1];
    }
    bool canAttend(vector<vector<int>> &arr) {
        
        // inshort there sould be no any overlap b/w any two intervals
        sort(arr.begin(),arr.end(),cmp);
        
        int n = arr.size();
        if(n == 1) return true;
        
        for(int i = 1;i<n;i++){
            int prevEnd = arr[i-1][1];
            int currentStart = arr[i][0];
            if(prevEnd>currentStart) return false;
        }
        
        return true;
        
    }
};

// Time Complexity : O(NlogN)// sorting time
// Space Complexity : O(N) // auxiliary sorting takes such space in any language