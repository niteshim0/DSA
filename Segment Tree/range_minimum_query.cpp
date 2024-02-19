void buildSegmentTree(int left, int right, int index, int nums[], int tree[]) {
    if (left == right) {
        tree[index] = nums[left];
        return;
    }
    int mid = left + (right - left) / 2;
    buildSegmentTree(left, mid, index * 2 + 1, nums, tree);
    buildSegmentTree(mid + 1, right, index * 2 + 2, nums, tree);
    tree[index] = min(tree[index * 2 + 1], tree[index * 2 + 2]);
}

int *constructST(int arr[], int n) {
    int *st = new int[4 * n + 2]; // Dynamically allocate memory
    buildSegmentTree(0, n - 1, 0, arr, st);
    return st;
}

int querySegmentTree(int queryLeft, int queryRight, int left, int right, int idx, int tree[]) {
    if (right < queryLeft || left > queryRight) return INT_MAX;

    if (left >= queryLeft && right <= queryRight) {
        return tree[idx];
    }
    int mid = left + (right - left) / 2;

    return min(querySegmentTree(queryLeft, queryRight, left, mid, idx * 2 + 1, tree),
               querySegmentTree(queryLeft, queryRight, mid + 1, right, idx * 2 + 2, tree));
}

int RMQ(int st[], int n, int a, int b) {
    return querySegmentTree(a, b, 0, n - 1, 0, st);
}