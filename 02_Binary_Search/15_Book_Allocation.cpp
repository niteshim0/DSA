class Solution {
public:
    bool canDistribute(const vector<int>& books, int students, int maxPages) {
        int requiredStudents = 1;
        int currentPages = 0;

        for (int pages : books) {
            if (currentPages + pages > maxPages) {
                requiredStudents++;
                currentPages = pages;
                if (requiredStudents > students) return false;
            } else {
                currentPages += pages;
            }
        }
        return true;
    }

    int findPages(vector<int>& books, int students) {
        int n = books.size();
        if (n < students) return -1;

        int start = 0, end = 0;
        for (int pages : books) {
            start = max(start, pages);  
            end += pages;           
        }

        int answer = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (canDistribute(books, students, mid)) {
                answer = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return answer;
    }
};
// Time Complexity : O(Nlog(Sum of Pages))
// Space Complexity : O(1)