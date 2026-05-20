// Product Pair
// https://www.geeksforgeeks.org/problem-of-the-day


// Concepts :: Two Pointers + Sorting + Hashmap + Alternate Version of Two Sum

// Approach I : Two Pointers

class Solution {
public:
    bool isProduct(vector<int>& arr,long long target){

        sort(arr.begin(),arr.end());

        int i=0;
        int j=arr.size()-1;

        while(i<j){

            long long prod=1LL*arr[i]*arr[j];

            if(prod==target)
                return true;

            if(prod<target)
                i++;
            else
                j--;
        }

        return false;
    }
};

// Time Complexity : O(NlogN)
// Space Complexity : O(N)


// Approach II : Hashmap

class Solution {
public:
    bool isProduct(vector<int>& arr, long long target) {
        
        unordered_map<long long,int> mp;

        for(int x : arr){
            mp[x]++;
        }

        for(int x : arr){

            if(x == 0){
                if(target == 0 && arr.size() > 1)
                    return true;
                continue;
            }

            if(target % x == 0){

                long long req = target / x;

                if(mp.count(req)){

                    // same number case
                    if(req == x){
                        if(mp[x] >= 2)
                            return true;
                    }
                    else{
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

// Time COmplexity:  O(N)
// Space Complexity : O(N)



/*
=========================================================
PAIR PRODUCT = TARGET : COMPLETE NOTES
=========================================================

PROBLEM:
Given an array, determine whether there exists
a pair (i,j) such that:

arr[i] * arr[j] = target


=========================================================
1) BRUTE FORCE
=========================================================

Idea:
Check every pair.

for(i=0 -> n-1)
    for(j=i+1 -> n-1)
        if(arr[i]*arr[j]==target)

Time : O(n²)
Space: O(1)

Use:
- Small constraints
- Baseline approach in interviews


=========================================================
2) HASHMAP / FREQUENCY MAP (BEST APPROACH)
=========================================================

Math:

a*b = target

Find:

b = target/a

Store frequency of all elements.

Steps:

1. Build frequency map
2. For each x:
      req = target/x
3. Search req in map


Time : O(n)
Space: O(n)


Pattern:
Two Sum Transformation

Two Sum:

a+b=target

Product Version:

a*b=target
b=target/a


=========================================================
IMPORTANT EDGE CASES
=========================================================


CASE 1:
Avoid division by zero

if(x==0)
    continue


----------------------------

CASE 2:
target=0

Because:

0*x=0

Need:
At least one zero and another element.

Examples:

[0,5] target=0

true


[0]

false


----------------------------

CASE 3:
Same element reuse issue

Example:

arr=[5]
target=25

Wrong:

5*5=25

Only one 5 exists.

Need:

mp[5]>=2


Correct:

if(req==x)
{
    if(mp[x]>=2)
        return true;
}


----------------------------

CASE 4:
Overflow

Wrong:

arr[i]*arr[j]

Correct:

1LL*arr[i]*arr[j]

Use:

long long

because:

100000 * 100000
exceeds int


=========================================================
3) SORT + TWO POINTER
=========================================================

Sort array

i=0
j=n-1

while(i<j)

compute product

Time:
O(nlogn)

Limitation:

Not reliable with:
- negatives
- zeros
- mixed values

Hashing is safer.


=========================================================
INTERVIEW THOUGHT PROCESS
=========================================================

Step 1:
Start with brute force

Step 2:
Observe equation

a*b=target

Transform:

b=target/a

Step 3:
Hashing optimization

Step 4:
Handle edge cases

- zero
- duplicates
- same element reuse
- overflow
- negatives


=========================================================
CORE CONCEPTS
=========================================================

1. Hashing

Store frequencies

mp[x]++


--------------------------------

2. Frequency Map

Useful for:

- duplicates
- counting
- pair search
- complements


--------------------------------

3. Two Sum Pattern

Very important:

a+b=target

convert to:

a*b=target


--------------------------------

4. Mathematical Transformation

Convert equation:

a*b=target

to:

b=target/a


=========================================================
TOP INTERVIEW QUESTIONS
=========================================================

EASY:

1. Two Sum
2. Contains Duplicate
3. Pair Sum
4. Intersection of Arrays
5. Count Pairs with Sum K


MEDIUM:

6. Two Sum II
7. Pair Difference K
8. Pair XOR
9. Subarray Sum K
10. Four Sum


ADVANCED:

11. 3Sum
12. 4Sum
13. K Sum
14. Pair Product < K
15. Count pair divisible by K


=========================================================
COMMON INTERVIEW QUESTIONS ASKED
=========================================================

1. Can duplicates exist?

2. Can negative numbers exist?

3. Can zeros exist?

4. Can same element be reused?

5. Overflow issue?

6. Can space be optimized?

7. Can you count all pairs
   instead of returning true/false?


=========================================================
PATTERN CATEGORY
=========================================================

Hashing
Frequency Array
Pair Problems
Complement Search
Two Sum Transformation
Mathematical Manipulation
Two Pointers


=========================================================
REMEMBER:

Brute Force
     ↓
Observe relation
     ↓
Transform equation
     ↓
Hashing
     ↓
Handle edge cases
     ↓
Optimal solution


This pattern appears repeatedly in DSA interviews.
=========================================================

*/