// Minimum K Consecutive Bit Flips
// https://www.geeksforgeeks.org/problems/minimum-number-of-k-consecutive-bit-flips--171650/1

// Concepts :: Greedy + Sliding Window + Simple Logic + Bit Manipulation + Binary Flipping + Deque

// ------  > Key Observation < ----------------------
/*
If we see a 0 at index i, we must flip starting from i.
Why?
Because the only way to change that 0 is to include it in a flip window.
So when we encounter:
0 → must flip
1 → do nothing
But there is a catch:
Flips affect future elements.
*/

// --------------------> Intuition <---------------------------------------
/*
When we flip k elements:
flip(i → i+k-1)
Every bit changes.
Example:
Original
0 1 0 1 1
Flip k=3 from index 0
1 0 1 1 1
So future bits depend on how many flips happened before them.
*/

// ----------------> Important Trick <--------------------------
/*
Instead of actually flipping the array every time:
We track whether current position is flipped or not.
Use:
actual_bit = arr[i] ^ flip_state
Where
flip_state = how many flips currently affecting this index
If:
actual_bit == 0
Then we must flip here.
*/

// Approach :: Brute Force Approach

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        for(int i = 0;i<=(n-k);i++){
            if(nums[i] == 0){
                for(int j = i;j<i+k;j++){
                    nums[j]^=1;
                }
                flips++;
            }
        }
        int zero = 0;
        for(int &x : nums){
            if(x == 0) return -1;
        }
        return flips;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)

// Approach 2 :: Greedy +  Sliding Window
/**
Instead of flipping every element physically.
We track flip effect.

-- Core Idea -- 
Maintain:
flip = current flip state

Also maintain an array: isFlipped[i]
Meaning: did we start a flip at index i?

Why?
Because flip only affects k elements.

After index:i + k
its effect should end.
*/
/*
-- Logic -- 

At index i

Step 1 : Remove expired flips
if(i >= k)
flip ^= isFlipped[i-k]

Step 2 : Check actual bit
actual = arr[i] ^ flip

If : actual == 0
We must flip.

Step 3 : Check if possible

If (i + k) > n
Impossible → return -1

Step 4 : Start flip
flips++
flip ^= 1
isFlipped[i] = 1
*/

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flip = 0;
        int ans = 0;
        vector<int> isFlipped(n,0);

        for(int i = 0;i<n;i++){
            if(i>=k){
                flip^=isFlipped[i-k]; // removing the effect of flip window , because this is no longer a part of k size flip window
            }
            if((nums[i]^flip) == 0){ // even after effect of prev flip 0 persists // so need to flip again
                if((i+k)>n) return -1; // flip window exceeds the boundary
                flip^=1; // this element gets flipped // flip = !flip; (handling odd even case) // if even flip its effect on actual num is zero // if odd then actual number has been reversed
                ans++; // 
                isFlipped[i] = 1;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)

/* -- Why Greedy Works -- 

When we see : actual_bit = 0
we must flip immediately.

If we delay, that bit will never be part of another window.
Thus greedy is forced → hence optimal.
*/

// there is also one deque solution of space complexity O(K) , which i don't find interesting , i think these are good enough.

// Approach 3 :: Tracking the flip window through input array
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flip = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){

            if(i >= k && nums[i-k] == 2){
                flip = !flip;
            }

            if(nums[i] == flip){

                if(i + k > n) return -1;

                ans++;
                flip  = !flip;
                nums[i] = 2;
            }
        }

        return ans;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)
