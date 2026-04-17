// LC 3761. Minimum Absolute Distance Between Mirror Pairs
// https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/description


// Concepts :: Hashmap + Reversal of Number

// Appraoch :: Traverse from left to right , and put reverseNumber inside the hashmap , and for each element check is it existing in the hashmap , if so calculate the diff b/w indices and if smaller update the minDiff , then update the hasmpa with latest reverseNum and its indices.
// Key Idea: Use a hash map to store the latest index of reversed numbers for O(1) lookup.



class Solution {
public:
    int reverseNum(int num){
       
       int revNum = 0;

       while(num!=0){
          
          int rem = num%10;
          revNum = revNum*10 + rem;
          num/=10;
       }

       return revNum;

    }
    int minMirrorPairDistance(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int n = nums.size();
        int mini = INT_MAX;

        for(int i = 0 ; i < n ; i++){

            int num = nums[i];
            int revNum = reverseNum(num);

            if(mp.count(num)){

                int diff =  i - mp[num];
                mini = min(mini,diff);
            }

            mp[revNum] = i;
        }

        return mini == INT_MAX ? -1 : mini;
         
    }
};


// Time Complexity : O(N * D) where D is length of largest element in nums
// Space Complexity : O(D)