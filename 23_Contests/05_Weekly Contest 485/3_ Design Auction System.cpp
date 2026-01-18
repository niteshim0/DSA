// 3815. Design Auction System
// https://leetcode.com/problems/design-auction-system/
// Concept :: Unordered_Map Knowledge + Priority Queue(by default c++ pq is maxHeap) + Object Oriented Programming

// Approach :: Do as said for every function add , remove , update
// during the update (i update the bids) , but doesn't remove the earlier bid(becuase that will lead to costly operations)
// During the getHighestBidder , i will delete these stale entries in maxHeap of an particular itemId
// for every top guy of itemId in maxHeap , we will check whether this exist in bids or not , if not then this is updated and it is stale entry so delete it , if its it bids , it means it is the guy we are searching for return it.

// During Contest :: Solved

class AuctionSystem {
private:
    unordered_map<int,unordered_map<int,int>> bids;
    unordered_map<int,priority_queue<pair<int,int>>> pq;
public:
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        
        bids[itemId][userId] = bidAmount;
        pq[itemId].push({bidAmount,userId}); 
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        
        bids[itemId][userId] = newAmount;
        pq[itemId].push({newAmount,userId}); 
    }
    
    void removeBid(int userId, int itemId) {
        
        bids[itemId].erase(userId);

        if(bids[itemId].empty()){
            bids.erase(itemId);
            pq.erase(itemId); 
        }
        
    }
    
    int getHighestBidder(int itemId) {
       
        if(pq.find(itemId) == pq.end()) return -1;

        auto &heap = pq[itemId];
        auto& currentBids = bids[itemId];

        while(!heap.empty()){

            auto [amount,userId] = heap.top();

            if(currentBids.count(userId) && currentBids[userId] == amount){
                return userId;
            }

            heap.pop() ; 
        }
        return -1;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */


 /** Time Complexity : 
// addBid = O(1) : Avg Case for insertion in unordered_map
           = O(logn) : for insertion in pq (since c++ uses by default binaryHeap(due to Heapify) for pq implementation internally)
// updateBid = O(1) // for updation
             = O(logn) // for insertion in pq
// removeBid = O(1) // for erasing a key in mp
             = O(1) // for deletion in mp
// getHighestBidder = Amortized(logn)
// Space Complexity : O(no of bids*sizeof(userId,amount) + no of itemId*(sizeof(bidamount,userId)))

// optimal solution :: yes
