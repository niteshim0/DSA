// 12. Range LCM Queries
// https://www.geeksforgeeks.org/problems/range-lcm-queries3348/1

// Concepts :: Segement Tree + Divide and Conquer + Recursion + Binary Tree + Arrays

// Approach :: Simply Build the segment tree , only change the merge operation make it lcm ,
// and also add function to calculate lcm  :: Do you rememeber HCF(num1,num2)(gcd) * LCM(num1,num2) = num1 * num2 => LCM(num1,num2) = (num1*num2) / GCD(num1,num2)

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

// Time Complexity 
// Building the tree : O(N)
// Update : O(logn) and Range : O(logN)
// Overall : O(n)

// Space Complexity : O(N) // the vector which gets used  + recursion stack space