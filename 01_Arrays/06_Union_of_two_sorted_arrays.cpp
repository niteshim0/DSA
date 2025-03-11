// https://www.naukri.com/code360/problems/sorted-array_6613259?leftPanelTabValue=SUBMISSION

/*1.Brute Force : - Store all the elements from two arrays into a set.
                  - Store the set elements into array.*/

vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    set<int> s(a.begin(),a.end());
    for(int x : b){
        s.insert(x);
    }
    vector<int> ans(s.begin(),s.end());
    return ans;
}
//Time Complexity : O(3N)
//Space Complexity : O(3N)

/*2.Optimal Approach : - Use two pointer approach.
                       - Iterate both array at same time and sort accordingly.*/

vector<int> sortedArray(vector<int> a, vector<int> b) {
    int i = 0, n = a.size();
    int j = 0, m = b.size();
    vector<int> ans;

    while (i < n && j < m) {
        // Skip duplicates in array a
        while (i < n - 1 && a[i] == a[i + 1]) {
            i++;
        }
        // Skip duplicates in array b
        while (j < m - 1 && b[j] == b[j + 1]) {
            j++;
        }

        if (a[i] < b[j]) {
            ans.push_back(a[i]);
            i++;
        } else if (a[i] > b[j]) {
            ans.push_back(b[j]);
            j++;
        } else {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }

    // Add remaining elements from array a
    while (i < n) {
        while (i < n - 1 && a[i] == a[i + 1]) {
            i++;
        }
        ans.push_back(a[i]);
        i++;
    }

    // Add remaining elements from array b
    while (j < m) {
        while (j < m - 1 && b[j] == b[j + 1]) {
            j++;
        }
        ans.push_back(b[j]);
        j++;
    }

    return ans;
}

// Time Complexity : O(N+M)
// Space Complexity : O(1)