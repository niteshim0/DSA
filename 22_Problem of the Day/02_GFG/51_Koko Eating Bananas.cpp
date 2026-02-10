// https://www.geeksforgeeks.org/problems/koko-eating-bananas/1
// Koko eating bananas
// Concept :: Binary Search on Answer

// Approach :: at 1 hr koko can max eat 1 banana at it can go till the max banana in 1 pile , we have to search the minimum no where it is possible to complete the pile in k hours.

class Solution {
public:
    bool isPossible(vector<int>& arr, long long speed, int k) {
        long long hours = 0;

        for (int num : arr) {
            hours += (num + speed - 1) / speed; 
            if (hours > k) return false;
        }

        return true;
    }

    int kokoEat(vector<int>& arr, int k) {
        long long start = 1;
        long long end = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while (start <= end) {
            long long mid = start + (end - start) / 2;

            if (isPossible(arr, mid, k)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};
