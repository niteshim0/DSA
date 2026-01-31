// 744. Find Smallest Letter Greater Than Target
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
// Concept :: Linear Search + Binary Search + ASCII of char



// Approach I : Linear Search
// We will hash every letter of array , and if we find the very first letter which is greater than our target , if not then return letters[0];
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> freq(26,0);
        for(char& ch : letters){
            freq[ch-'a']++;
        }
        for(int i = 0;i<26;i++){
            int need = target - 'a';
            if(freq[i]>0 && i>need){
                char ans = char(i+97);
                return ans;
            }
        }
        return letters[0];
    }
};
// Time Complexity : O(N)
// Space Complexity : O(26)

// Approach II :: Binary Search
// Since array is already sorted in increasing order , then find the upper bound of that target , if it exists return it otherwise return first letter of letters.

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int ans = -1;
        int start = 0 , end = n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(letters[mid]>target){
                ans = mid;
                end = mid-1;
            }else{
                start = mid + 1;
            }
        }
        return ans == -1 ? letters[0] : letters[ans];
    }
};

// Time Complexity : O(logN)
// Space Complexity : O(1)