// LC 3075. Maximize Happiness of Selected Children
// https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2025-12-25
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        
        long long totalHappinessSum = 0;
        int turns = 0;
        
        for(int i = 0; i < k; i++) {
            totalHappinessSum += max(happiness[i] - turns, 0);  
            turns++; 
        }
        
        return totalHappinessSum;
    }
};

/*
Complexity Analysis
Given n as the length of happiness,

Time complexity: O(n⋅logn)

Sorting the happiness array requires O(n⋅logn) time.

Iterating through the first k elements of the sorted array takes O(k) time.

Inside the loop, the max() function and addition operations take constant time.

Overall, the time complexity of the solution is dominated by the sorting step, making the time complexity O(n⋅logn).

Space complexity: O(n)

In Python, the sort method sorts a list using the Timesort algorithm which is a combination of Merge Sort and Insertion Sort and has O(n) additional space.

In C++, the sort() function is implemented as a hybrid of Quick Sort, Heap Sort, and Insertion Sort, with a worse-case space complexity of O(logn).

In Java, Arrays.sort() is implemented using a variant of the Quick Sort algorithm which has a space complexity of O(logn) for sorting two arrays. We also convert the array into an Integer array which has an additional space complexity of O(n).

As the dominating term is O(n), the overall space complexity is O(n).


*/