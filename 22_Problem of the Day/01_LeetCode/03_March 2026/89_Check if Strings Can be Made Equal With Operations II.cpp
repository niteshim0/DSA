// LC 2840. Check if Strings Can be Made Equal With Operations II
// https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description

// Concepts :: Counting + Array + Swapping


// Approach :: In both the strings , if they get sorted , elements at even and odd position should be same in both the strings


// Technique 1 :: Sorting

class Solution {
public:
    bool checkStrings(string s1, string s2) {
         
        int n = s1.size();
        
        vector<char> firstOdd , secondOdd , firstEven , secondEven;

        for(int i = 0 ;i < n; i++){

            if(i&1){
                firstOdd.push_back(s1[i]);
                secondOdd.push_back(s2[i]);
            }else{
                firstEven.push_back(s1[i]);
                secondEven.push_back(s2[i]);
            }
        }

        sort(firstOdd.begin(),firstOdd.end());
        sort(secondOdd.begin(),secondOdd.end());
        sort(firstEven.begin(),firstEven.end());
        sort(secondEven.begin(),secondEven.end());

        return (firstOdd == secondOdd) && (firstEven == secondEven);
    }
};

// Time Complexity : O(NLogN)
// Space Complexity : O(N)



// Appraoch II : Frequency Array

class Solution {
public:
    bool isEqual(vector<char>& first , vector<char>& second){

        vector<int> hash(26,0);

        for(char& ch : first){
            hash[ch-'a']++;
        }

        for(char& ch : second){
            hash[ch-'a']--;
        }

        for(int i = 0;i<26;i++){
            if(hash[i]!=0) return false;
        }

        return true;
    }
    bool checkStrings(string s1, string s2) {
         
        int n = s1.size();
        
        vector<char> firstOdd , secondOdd , firstEven , secondEven;

        for(int i = 0 ;i < n; i++){

            if(i&1){
                firstOdd.push_back(s1[i]);
                secondOdd.push_back(s2[i]);
            }else{
                firstEven.push_back(s1[i]);
                secondEven.push_back(s2[i]);
            }
        }

        return isEqual(firstOdd, secondOdd) && isEqual(firstEven, secondEven);
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)