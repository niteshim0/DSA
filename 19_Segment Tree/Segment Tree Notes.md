# Segment Tree

## Phase 1 :: Q. What problem does Segment Tree solves ?

- We will see it through an example:
- Suppose arr = [1 2 3 4 5] and queries sum(1,4), sum(0,4), sum(2,4)

- Different approaches to solve this problem :

  - `Brute Force Approach` : Every query will take O(n) , if n = 1e5 and q = 1e5 then O(n*q) = 1e10 --> `Too slow`.

  - `Prefix Sum Approach ` : It helps makes the range query O(1) , but still updation takes O(N) because we also need to change all the future prefix value , ultimately leading to O(N*Q) --> `Again Too Slow!`

  - That's where the segment tree comes into the picture , it solves both these problems : 
    - `Query : O(logn)`
    - `Update : O(logn) `

  - Core Idea : `Store answer for ranges`.
    - Example : [1 2 3 4] then store divison of 
      - 4 : [1 2 3 4] = 10
      - 2 : [1 2] = 3 and [3 4] = 7
      - 1 : [1] = 1 , [2] = 2 , [3] = 3 and [4] = 4
    
    - Typical Divide and Conquer Behaviour
  
    - This forms a binary tree for [1 2 3 4] the segment tree sturcutre looks like : 
                        
                10
               /  \
              3     7
             /  \   / \
            1    2 3   4

    - Key Point : `Each node stores answer for a segment`.

    - Each node covers a range : 10 -> sum(0,3)
                               : 3  -> sum(0,1)
                               : 7  -> sum(2,3)
    
    - For the visualisation purposes, we have thought of it as tree , but its implementation will be done by array or vector only.

    - **Segement Tree Array Representation**
      - We store tree in array :
        ```c++
              vector<int> seg(4*n);
              // Why 4 * n ? -> its generally safe size in dealing with segment trees to avoid out of bound error.
        ```
    
    - **Most Important Functions of Segment Tree**

      - Everything revolves around these 4 functions only :
          ```c++
              build()
              query()
              update()
               merge() // its implementation only changes in problem according to different conditions , all other functions remains same
          ```

## Phase 2 :: Building Segment Tree

- Suppose arr = [ 12 3 4] , Goal : Build Segment Tree

### Build Logic

- `Leaf Node `:
  -  If low == high , then single element segment , store 
  ```c++
      seg[idx] = arr[low];
  ```

- `Internal Nodes` : 
    - Split it into two halves.
    - Mid = (low) + (high-low)/2;
    - Build : Left Child and Right Child
    - Merge

### Build Template

  ```c++
         void build(int idx,int low,int high,vector<int>& arr){

            if(low == high){
                seg[idx] = arr[low];
                  return;
            }         

            int mid = (low + high)/2;

            build(2*idx+1,low,mid,arr);

            build(2*idx+2,mid+1,high,arr);

            seg[idx] = seg[2*idx+1] + seg[2*idx+2]; // This one line is the entire crux of segment tree // result of range left + result of range right

        }
  ```

## Phase 3 :: Range Query

- Suppose query(1,3) , We recursively travels only useful segments

### Three Cases :

  - **1.`No Overlap` ::**  segement outside query -> return neutral value , in case of sum return 0.

  - **2.`Complete Overlap` ::** Take stored answer directly .
      ```c++
         return seg[idx];
      ```

  - **3.`Partial Overlap` ::** Go both sides and merge answers.
    
### Query Template

```c++
int query(int idx,int low,int high,int l,int r){

    // no overlap
    if(high < l || low > r){
        return 0;
    }

    // complete overlap
    if(low >= l && high <= r){
        return seg[idx];
    }

    int mid = (low + high)/2;

    int left = query(2*idx+1,low,mid,l,r);

    int right = query(2*idx+2,mid+1,high,l,r);

    return left + right;
}
```

## Phase 4 :: Point Update

- Suppose: arr[2] = 10 , only nodes containing index 2 change.

### Update Template

```c++
void update(int idx,int low,int high,int i,int val){

    if(low == high){
        seg[idx] = val;
        return;
    }

    int mid = (low + high)/2;

    if(i <= mid){
        update(2*idx+1,low,mid,i,val);
    }
    else{
        update(2*idx+2,mid+1,high,i,val);
    }

    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}
```

- Ability to solve problems like :
  
  - Range Sum Query
  - Range Min Query
  - Range Max Query
  - Range XOR Query
  - Range GCD Query
  - Range LCM Query

// I have solved today Range LCM Query as it was part of GFG POTD

```c++
class Solution {
  public:
   long long gcd(long long a, long long b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    vector<long long> segTree;

    void build(int idx, int low, int high, vector<int>& arr) {

        if(low == high) {
            segTree[idx] = arr[low];
            return;
        }

        int mid = (low + high) / 2;

        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);

        segTree[idx] = lcm(segTree[2 * idx + 1],
                           segTree[2 * idx + 2]);
    }

    void update(int idx, int low, int high,
                int pos, int val) {

        if(low == high) {
            segTree[idx] = val;
            return;
        }

        int mid = (low + high) / 2;

        if(pos <= mid) {
            update(2 * idx + 1, low, mid, pos, val);
        }
        else {
            update(2 * idx + 2, mid + 1, high, pos, val);
        }

        segTree[idx] = lcm(segTree[2 * idx + 1],
                           segTree[2 * idx + 2]);
    }

    long long query(int idx, int low, int high,
                    int l, int r) {

        // no overlap
        if(high < l || low > r) {
            return 1;
        }

        // complete overlap
        if(low >= l && high <= r) {
            return segTree[idx];
        }

        int mid = (low + high) / 2;

        long long left = query(2 * idx + 1,
                               low, mid, l, r);

        long long right = query(2 * idx + 2,
                                mid + 1, high, l, r);

        return lcm(left, right);
    }
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        
         int n = arr.size();

        segTree.resize(4 * n);

        build(0, 0, n - 1, arr);

        vector<long long> ans;

        for(auto &q : queries) {

            // Update Query
            if(q[0] == 1) {

                int index = q[1];
                int value = q[2];

                update(0, 0, n - 1, index, value);
            }

            // Range Query
            else {

                int l = q[1];
                int r = q[2];

                ans.push_back(
                    query(0, 0, n - 1, l, r)
                );
            }
        }

        return ans;
        
    }
};
```



           









