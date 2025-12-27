// 2402. Meeting Rooms III
// https://leetcode.com/problems/meeting-rooms-iii/?envType=daily-question&envId=2025-12-27

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());

        vector<int> meetingCnt(n,0);

        priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> usedRooms;

        priority_queue<int, vector<int>, greater<int>> unusedRooms;

        for(int i = 0;i<n;i++){
            unusedRooms.push(i);
        }

        for(auto& meeting : meetings){
            int start = meeting[0] , end = meeting[1];
            
            while(!usedRooms.empty() && usedRooms.top().first<=start){
                int room = usedRooms.top().second;
                usedRooms.pop();
                unusedRooms.push(room);
            }
            if(!unusedRooms.empty()){
                int room = unusedRooms.top();
                unusedRooms.pop();
                usedRooms.push({end,room});
                meetingCnt[room]++;
            }else{
                auto [roomAvailableTime,room] = usedRooms.top();
                usedRooms.pop();
                usedRooms.push({roomAvailableTime + end-start,room});
                meetingCnt[room]++;
            }
        }

        int maxCnt = 0;
        int lowestRoom = 0;
        for(int i = 0;i<n;i++){
            if(meetingCnt[i]>maxCnt){
                maxCnt = meetingCnt[i];
                lowestRoom = i;
            }
        }

        return lowestRoom;
    }
};

// Time Complexity : O(MlogM)
// Space Complexity : O(M)



// This problem simply maps to First Come First Serve CPU Scheduling.
/*
| LeetCode Problem | Operating System Concept      |
| ---------------- | ----------------------------- |
| Meeting          | Process / Job                 |
| Room             | CPU core                      |
| Start time       | Arrival time                  |
| End time         | Execution duration            |
| Delayed meeting  | Process waiting (ready queue) |
| Room reused      | CPU context switching         |
| Priority queue   | Scheduler data structure      |

*/