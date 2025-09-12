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

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */