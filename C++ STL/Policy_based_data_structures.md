# GNU Policy-Based Data Structures (PBDS) Library

The PBDS (Policy-Based Data Structures) library, also known as the GNU Policy-Based Data Structures (PBDS) library, is an extension to the C++ Standard Template Library (STL) provided by GNU. It offers additional data structures that are not available in the standard STL, such as ordered sets, ordered multisets, and hash tables with multiple values per key.

## Features

- **Policy-Based Design**: Users can customize the behavior and characteristics of the data structures by providing different policies during instantiation.
- **Customizable Behavior**: Policies control various aspects of the data structure, such as ordering, duplication, hashing, and updating.
- **Advanced Data Structures**: Provides efficient implementations of advanced data structures like balanced binary search trees (Red-Black Trees, AVL Trees, Splay Trees,Fenwick Trees).
- **Efficient Operations**: Supports efficient operations like insertion, deletion, and finding order statistics (such as the k-th smallest or largest element).

## Usage

The PBDS library is commonly used in competitive programming and algorithmic contests due to its efficient implementations of advanced data structures and algorithms. It provides functionality beyond what's available in the standard C++ library, enabling programmers to solve complex problems more effectively.

## Example 1 . Ordered_Set

This example demonstrates the usage of the `ordered_set` data structure provided by the GNU PBDS library. It includes features like ordered statistics, finding the number of elements greater than a specified value, and handling duplicate elements.

###  Including PBDS Libarary 
  ```cpp

   #include<ext/pb_ds/assoc_container.hpp>
   #include<ext/pb_ds/tree_policy.hpp>
   using namespace __gnu_pbds;

  ```

  The following code snippet demonstrates the usage of the GNU PBDS (Policy-Based Data Structures) library:

  1. `#include <ext/pb_ds/assoc_container.hpp>:` This header provides the necessary infrastructure for using associative containers like trees (including tree) provided by the PBDS library.

  2. `#include <ext/pb_ds/tree_policy.hpp>`: This header contains various policies that can be used with the tree container, such as tree_order_statistics_node_update which helps in keeping track of order statistics during tree updates.

  3. `using namespace __gnu_pbds` : This line brings the `__gnu_pbds namespace` into the current scope. The PBDS library is encapsulated within this namespace. It contains various classes and functions related to policy-based data structures, including the tree container.

### Defining the Data Structure of the PBDS library:

   ```cpp
   typedef tree<
    int,                    // Key type: int
    null_type,              // Mapped type: null_type (no associated value)
    less_equal<int>,        // Comparison function: less_equal<int> (allows duplicate keys)
    rb_tree_tag,            // Tree type: Red-Black Tree
    tree_order_statistics_node_update // Node update policy
    > ordered_set; //datatype name
   ```

  - **int**: Specifies the type of keys in the set. In this case, it's an integer.

  - **null_type**: Specifies the type of associated value each key maps to. `null_type` means there's no associated value.

  - **less_equal<int>**: Specifies the comparison function for ordering elements in the set. `less_equal<int>` is a comparison function that allows duplicate keys. It orders elements in non-decreasing order.

  - **rb_tree_tag**: Specifies the type of tree to use for implementing the set. In this case, it's a Red-Black Tree (`rb_tree_tag`). Red-Black Trees are self-balancing binary search trees.

  - **tree_order_statistics_node_update**: Specifies the node update policy. It's used for updating the tree when nodes are inserted or deleted. This policy allows the tree to keep track of the order statistics of the elements (like finding the k-th smallest or largest element efficiently).


 ## Solving one LeetCode hard question using it : 
  
  - It can be also solved using Segment Tree in C++ , or you are pro in python you can use sortedContainer for solving the same.

 ## Q. **[LC 3072.Distribute Elements Into Two Arrays II](https://leetcode.com/problems/distribute-elements-into-two-arrays-ii/description/)**

   

You are given a 1-indexed array of integers nums of length n.

We define a function greaterCount such that greaterCount(arr, val) returns the number of elements in arr that are strictly greater than val.

You need to distribute all the elements of nums between two arrays arr1 and arr2 using n operations. In the first operation, append nums[1] to arr1. In the second operation, append nums[2] to arr2. Afterwards, in the ith operation:

- If greaterCount(arr1, nums[i]) > greaterCount(arr2, nums[i]), append nums[i] to arr1.
- If greaterCount(arr1, nums[i]) < greaterCount(arr2, nums[i]), append nums[i] to arr2.
- If greaterCount(arr1, nums[i]) == greaterCount(arr2, nums[i]), append nums[i] to the array with a lesser number of elements.
- If there is still a tie, append nums[i] to arr1.

The array result is formed by concatenating the arrays arr1 and arr2. For example, if arr1 == [1,2,3] and arr2 == [4,5,6], then result = [1,2,3,4,5,6].

Return the integer array result.

### Constraints:

- 3 <= n <= 10^5
- 1 <= nums[i] <= 10^9

### Examples:

**Input**: nums = [3,3,3,3]  
**Output**: [3,3,3,3]

**Input**: nums = [5,14,3,1,2]  
**Output**: [5,3,1,2,14]

**Input**: nums = [2,1,3,3]  
**Output**: [2,3,1,3]


## Solution:

In this question, there isn't a particular intuition to follow; one simply needs to follow the instructions given in the question. However, a bigger challenge lies in finding suitable data structures to achieve the desired outcome.

### Data Structure 1: Using Vector or Vector-Like

#### Prerequisites:

1. **Inserting X element in Set**: 
   - Complexity: O(N) if we want to keep it sorted

2. **Duplicacy**:
   - It allows duplicates

3. **Finding elements greater than X**:
   - Complexity: O(logN) using binary search

### Data Structure 2: Using Set or Set-Like

#### Prerequisites:

1. **Inserting X element in Set**:
   - Complexity: O(logN)

2. **Duplicacy**:
   - It doesn't allow duplicates

3. **Finding elements greater than X**:
   - Complexity: O(logN) using `upper_bound`

### Data Structure 3: Using Ordered_set from PBDS

#### Prerequisites:

1. **Inserting X element in Set**:
   - Complexity: O(logN)

2. **Duplicacy**:
   - It allows duplicates

3. **Finding elements greater than X**:
   - Complexity: O(log(N)) using `ordered_set.order_of_key(X+1)`

## Verdict : Use Ordered_Set From PBDS library

## Code :
 
 ```cpp

  #include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
         int n=nums.size();
        
        vector<int>ans,n1,n2;
        ordered_set n11,n22;
        
        
        n1.push_back(nums[0]);
        n2.push_back(nums[1]);
        
        n11.insert(nums[0]);
        n22.insert(nums[1]);
        
        
        for(int i=2;i<n;i++){
            int v1=n1.size()-n11.order_of_key(nums[i]+1);
            int v2=n2.size()-n22.order_of_key(nums[i]+1);
            
            if(v1>v2){
                n1.push_back(nums[i]);
                n11.insert(nums[i]);
            }
            else if(v2>v1){
                n2.push_back(nums[i]);
                n22.insert(nums[i]);
            }
            else{
                if(n1.size()<=n2.size()){
                    n1.push_back(nums[i]);
                n11.insert(nums[i]);
                }
                else{
                    n2.push_back(nums[i]);
                n22.insert(nums[i]);
                }
            }
        }
        
   
        
        for(auto x:n1)ans.push_back(x);
        for(auto x:n2)ans.push_back(x);
        
        return ans;
    }
};
 ```

    
  


  

