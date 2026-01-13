// LC 3453 . Separate Squares I
// https://leetcode.com/problems/separate-squares-i/description
// Concept :: Binary Search on Answers
// Binary search is done on a monotonic condition, not equality
// while dealing with double ans , binary search never move abs(1)
// and start<=end never be case , make it according to question preceision // end - start > 1e-6

class Solution {
public:
    bool isFeasible(vector<vector<int>>& squares, double mid) {
        double beforeMid = 0.0;
        double afterMid  = 0.0;

        for (auto &square : squares) {
            double bottom = square[1];
            double side   = square[2];
            double top    = bottom + side;

            if (top <= mid) {
                beforeMid += side * side;
            }
            else if (bottom >= mid) {
                afterMid += side * side;
            }
            else {
                double beforeLen = mid - bottom;
                double afterLen  = top - mid;

                beforeMid += beforeLen * side;
                afterMid  += afterLen * side;
            }
        }

        return beforeMid >= afterMid;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double start = 0.0, end = 1e9;

        while (end - start > 1e-6) {
            double mid = start + (end - start) / 2.0;

            if (isFeasible(squares, mid))
                end = mid;
            else
                start = mid;
        }

        return start;
    }
};

// Time Complexity : O(NLogN)
// Space Complexity : O(1)