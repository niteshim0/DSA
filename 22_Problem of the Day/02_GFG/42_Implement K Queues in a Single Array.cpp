// Implement K Queues in a Single Array
// https://www.geeksforgeeks.org/problems/implement-k-queues-in-a-single-array/1

class kQueues {
   vector<int> arr , front , rear , next;
   int emptySpot;
  public:
    kQueues(int n, int k) {
        arr.resize(n);
        front.assign(k,-1);
        rear.assign(k,-1);
        next.resize(n);
        emptySpot = 0;
        
        for(int i = 0;i<n-1;i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
    }

    void enqueue(int x, int i) {
        if(emptySpot == -1) return;
        int idx = emptySpot;
        emptySpot = next[idx];
        if(front[i] == -1) front[i] = idx;
        else next[rear[i]] = idx;
        
        next[idx] = -1;
        rear[i] = idx;
        arr[idx] = x;
    }

    int dequeue(int i) {
        if(front[i] == -1) return -1;
        int idx = front[i];
        front[i] = next[idx];
        if(front[i] == -1) rear[i] = -1;
        
        next[idx] = emptySpot;
        emptySpot = idx;
        return arr[idx];
    }

    bool isEmpty(int i) {
        return front[i] == -1;
    }

    bool isFull() {
        return emptySpot == -1;
    }
};

// Enqueue : O(1)
// Dequeue : O(1)
// constructor : O(N)
// space : O(N + K)