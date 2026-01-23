// 3507. Minimum Pair Removal to Sort Array II
// https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/description/
// Concept :: Sometimes Brute Force is Enough


class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while(nums.size()>1){
            bool isAscending = true;
            int minSum = std::numeric_limits<int>::max();
            int targetIdx = -1;

            for(int i = 0;i<nums.size()-1;i++){
                int sum = nums[i] + nums[i+1];

                if(nums[i]>nums[i+1]){
                    isAscending = false;
                }
                if(sum<minSum){
                    minSum = sum;
                    targetIdx = i;
                }
            }
            if(isAscending) break;
            cnt++;
            nums[targetIdx] = minSum;
            nums.erase(nums.begin() + targetIdx+1);
        }

        return cnt;
    }
};

// Time Complexity : O(N*N)
// Space Complexity : O(1)



// Priority Queue + Lazy Deletion Technique

typedef long long ll;

const int MAX_N = 100005;

struct Node {
    ll value;
    int left;
};

using ListIt = std::list<Node>::iterator;

struct Pair {
    ListIt first;
    ListIt second;
    ll cost;
    size_t firstLeft;
    size_t secondLeft;

    Pair() {}
    Pair(ListIt fi, ListIt se, ll cost)
        : first(fi),
          second(se),
          firstLeft(fi->left),
          secondLeft(se->left),
          cost(cost) {}
};

struct ComparePair {
    bool operator()(const Pair& a, const Pair& b) {
        if (a.cost != b.cost) {
            return a.cost > b.cost;
        }
        return a.firstLeft > b.firstLeft;
    }
};

class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        std::list<Node> list;
        std::bitset<MAX_N> merged;
        std::priority_queue<Pair, std::vector<Pair>, ComparePair> pq;

        int decreaseCount = 0;
        int count = 0;

        list.push_back({nums[0], 0});

        for (size_t i = 1; i < nums.size(); ++i) {
            list.push_back({nums[i], (int)i});

            auto curr = std::prev(list.end());
            auto prev = std::prev(curr);

            pq.push({prev, curr, prev->value + curr->value});

            if (nums[i - 1] > nums[i]) {
                decreaseCount++;
            }
        }

        while (decreaseCount > 0 && !pq.empty()) {
            auto top = pq.top();
            pq.pop();

            if (merged[top.firstLeft] || merged[top.secondLeft]) {
                continue;
            }

            auto first = top.first;
            auto second = top.second;
            auto cost = top.cost;

            if (first->value + second->value != cost) {
                continue;
            }

            count++;

            if (first->value > second->value) {
                decreaseCount--;
            }

            ListIt prev =
                (first == list.begin()) ? list.end() : std::prev(first);
            ListIt next = std::next(second);

            if (prev != list.end()) {
                if (prev->value > first->value && prev->value <= cost) {
                    decreaseCount--;
                }
                if (prev->value <= first->value && prev->value > cost) {
                    decreaseCount++;
                }
                pq.push({prev, first, prev->value + cost});
            }

            if (next != list.end()) {
                if (second->value > next->value && cost <= next->value) {
                    decreaseCount--;
                }
                if (second->value <= next->value && cost > next->value) {
                    decreaseCount++;
                }
                pq.push({first, next, cost + next->value});
            }

            first->value = cost;
            merged[second->left] = 1;
            list.erase(second);
        }

        return count;
    }
};

// Time Complexity : O(NlogN)
// Space Complexity : O(N)