// Brute Force Approach
// Already stored the section length b/w two adjacent stations.
// Counted how many parts one can do to get minimal length.
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> howMany(n-1,0);
        for(int gasStations = 1;gasStations<=k;gasStations++){
            long double sectionLength = -1;
            int maxIdx = -1;
            for(int i = 0;i<n-1;i++){
                long double diff = arr[i+1]-arr[i];
                long double section = diff/(long double)(howMany[i]+1);
                if(section>sectionLength){
                    sectionLength = section;
                    maxIdx = i;
                }
            }
            howMany[maxIdx]++;
        }
        long double maxAns = -1;
        for(int i = 0;i<n-1;i++){
                long double diff = arr[i+1]-arr[i];
                long double section = diff/(long double)(howMany[i]+1);
                if(section>maxAns){
                    maxAns = section;
                }
        }
        return maxAns;
    }
};
// Time Complexity : O(N*N)
// Space Complexity : O(N)

// Priority Queue Approach
// For finding the max element we will use priority queue
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> howMany(n - 1, 0);
        priority_queue<pair<double, int>> pq;

        // Initialize priority queue with segment lengths
        for (int i = 0; i < n - 1; i++) {
            double segmentLength = arr[i + 1] - arr[i];
            pq.push({segmentLength, i});
        }

        // Distribute k additional stations
        for (int i = 0; i < k; i++) {
            auto topElement = pq.top();
            pq.pop();
            int idx = topElement.second;
            howMany[idx]++; // Add a new station

            double originalLength = arr[idx + 1] - arr[idx];
            double newLength = originalLength / (howMany[idx] + 1);
            pq.push({newLength, idx});
        }

        return pq.top().first;
    }
};
// Time Complexity : O(NlogN)
// Space Complexity:O(N)


// Binary Search Questions
class Solution {
  public:
    long long  noOfGasStations(long double dist, vector<int> &arr) {
        long long cnt = 0;
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            long long inb = (arr[i] - arr[i - 1])/dist;
            // if completely divisible // then gas station lies on the rborders
            // so -1
            if((arr[i] - arr[i-1]) == (dist * inb)) {
              inb--; 
            }
            cnt += inb;
        }
        return cnt;
    }

    double findSmallestMaxDist(vector<int> &arr, int k) {
        long double start = 0;
        long double end = 0;
        long double ans = -1;
        int n = arr.size();

        for (int i = 1; i < n; i++) {
            end = max(end, (long double)(arr[i] - arr[i - 1]));
        }

        long double diff = 1e-6;
        while (end - start > diff) {
            long double mid = (start + end) / 2.0;
            long long cnt = noOfGasStations(mid, arr);
            if (cnt > k) {
                start = mid;
            } else {
                ans = mid;
                end = mid;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*logN)
// Space Complexity : O(1)

