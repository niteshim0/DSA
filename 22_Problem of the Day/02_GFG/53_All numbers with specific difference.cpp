// All numbers with specific difference
// https://www.geeksforgeeks.org/problems/all-numbers-with-specific-difference3558/1

// Concepts :: Binary Search + Binary Search on Answers

// Intuition :: 
/*
If some number k satisfies:

k−sum(k)≥d

Then all numbers greater than k will also satisfy it.

This means:

✔ Condition becomes monotonic
❗ Once true → always true afterward

That means:

👉 We can use Binary Search
*/

class Solution {
  public:
    bool isDiffSumEquals(int mid,int d){
        int n = mid;
        int sum = 0;
        
        while(n>0){
            sum+=(n%10);
            n/=10;
        }
        
        return (mid-sum)>=d;
    }
    int getCount(int n, int d) {
        
        int start = 1 , end = n;
        int ans = 0;
        
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(isDiffSumEquals(mid,d)){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        
        
        return ans==0 ? 0 : n-ans+1;
        
    }
};


// Complexity
// Time
// Digit sum calculation:
// O(log10(n)) → number of digits
// Binary Search:
// O(log n)
// Total:
// O(logn×logn)

// Space :: O(1)