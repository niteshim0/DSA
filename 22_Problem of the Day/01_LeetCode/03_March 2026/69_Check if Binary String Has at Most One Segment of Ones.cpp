// LC 1784. Check if Binary String Has at Most One Segment of Ones
// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones

// Concepts :: Kadane's Algorithm + Logical Reasoning + Simple Aptitude

// Approach I:: We will just count how many times continous segment of 1 occurs , if its more than one , we will return false , otherwise return false.
class Solution {
public:
    bool checkOnesSegment(string s) {
        int oneCntinousSegment = 0;
        int cnt = 0;
        for(char &ch : s){
            if(ch == '1'){
                cnt++;
            }else{
                if(cnt!=0) oneCntinousSegment++;
                if( oneCntinousSegment>1) break;
                cnt = 0;
            }
        }
        
        if(cnt!=0) oneCntinousSegment++;
        return  (oneCntinousSegment>1) ? false : true;
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

// Approach II :
// Since string contains no leading zeroes , so if its contain '01' as substring , then it surely contains more than 1 continous segment of 1's , return false; 

class Solution {
public:
    bool checkOnesSegment(string s) { 
        return s.find("01") == string::npos; 
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)