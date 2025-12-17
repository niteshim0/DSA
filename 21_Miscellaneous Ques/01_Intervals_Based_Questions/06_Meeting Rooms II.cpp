// https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1

class Solution {
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n = start.size();
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int rooms = 0;
        int endPtr = 0;

        for(int i = 0; i < n; i++){
            if(start[i] < end[endPtr]){
                rooms++;
            } else {
                endPtr++;
            }
        }
        return rooms;
    }
};
// Time Complexity : O(NlogN)
// Space Complexity : O(N)