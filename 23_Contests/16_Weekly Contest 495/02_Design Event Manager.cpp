// LC 3885. Design Event Manager
// https://leetcode.com/problems/design-event-manager/

// Concepts :: Object Oriented Programming + Priority Queue + Hashing + Lazy Deletion

// Approach :: Push all those things in priority queue and in hashing , updatePriority and pollHighest


class EventManager {
public:
    unordered_map<int,int> mp;
    priority_queue<pair<int,int>> pq;
    EventManager(vector<vector<int>>& events) {

        for(auto &event : events){

            int eventId = event[0] , priority = event[1];
            mp[eventId] = priority;
            pq.push({priority,-eventId});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId] = newPriority;
        pq.push({newPriority , -eventId});
    }
    
    int pollHighest() {
        
        while(!pq.empty()){
            auto [priority, eventId] = pq.top();
            eventId*=-1;
            if(mp.count(eventId) && mp[eventId] == priority){
                pq.pop();
                mp.erase(eventId);
                return eventId;
            }
            pq.pop();
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */


// Time Complexity :: O(N)
// Space Complexity :: O(N)