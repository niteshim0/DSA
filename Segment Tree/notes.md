# Segment Trees

## Overview
- A Segment Tree is a data structure used for efficiently handling range queries and updates on an array.
- Unlike traditional tree structures with pointers and left/right child nodes, it is conceptually visualized as a binary tree derived from an array representation similar to Heap.
- It stores information about array intervals in a tree-like structure, enabling quick query responses and array modifications.
- Range queries, such as finding sum or minimum elements within a specified range, can be performed in O(log n) time.
- Supports array modifications like element replacement or updating all elements in a subsegment efficiently.

## Functionality
- Efficiently answers queries like sum of consecutive array elements or finding minimum element within a range.
- Supports array modifications, including element replacement and updating values in a subsegment.

## Advanced Usage
- Can be extended for more complex operations and queries.
- Two-dimensional Segment Trees enable operations on matrices, like sum or minimum queries over subrectangles, in O(log^2 n) time.

## Memory Efficiency
- Requires linear memory usage.
- Conceptually visualized as a binary tree derived from an array, similar to how heaps are represented.
- The standard Segment Tree needs 4n vertices for an array of size n.

## Basic Segment Tree Code
```c++
  //https://leetcode.com/problems/range-sum-query-mutable/
class NumArray {
public:
    vector<int> tree;
    int n;
    int left;
    int right;
    void buildSegmentTree(int left, int right, int index, vector<int>& nums) {
        if (left == right) {
            tree[index] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildSegmentTree(left, mid, index * 2 + 1, nums);
        buildSegmentTree(mid + 1, right, index * 2 + 2, nums);
        tree[index] = tree[index * 2 + 1] + tree[index * 2 + 2];
    }
    void updateSegmentTree(int upIdx, int val, int left, int right, int i) {
        if (left == right) {
            tree[i] = val;
            return;
        }
        int mid = left + (right - left) / 2;
        if (upIdx <= mid) {
            updateSegmentTree(upIdx, val, left, mid, i * 2 + 1);
        } else {
            updateSegmentTree(upIdx, val, mid + 1, right, i * 2 + 2);
        }
        tree[i] = tree[i * 2 + 1] + tree[i * 2 + 2];
    }
    int querySegmentTree(int queryLeft, int queryRight, int left, int right, int idx) {
        if (right < queryLeft || left > queryRight) return 0;

        if (left >= queryLeft && right <= queryRight) {
            return tree[idx];
        }
        int mid = left + (right - left) / 2;

        return querySegmentTree(queryLeft, queryRight, left, mid, idx * 2 + 1) + querySegmentTree(queryLeft, queryRight, mid + 1, right, idx * 2 + 2);
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n); 
        left = 0;
        right = n - 1;
        buildSegmentTree(left, right, 0, nums);
    }

    void update(int index, int val) {
        updateSegmentTree(index, val, left, right, 0);
    }

    int sumRange(int queryLeft, int queryRight) {
        return querySegmentTree(queryLeft, queryRight, left, right, 0);
    }
};
```
