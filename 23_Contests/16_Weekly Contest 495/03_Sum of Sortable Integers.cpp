// LC 3886. Sum of Sortable Integers
// https://leetcode.com/problems/sum-of-sortable-integers/description/


// Concepts :: Sorting + Generating Divisors + KMP (Pattern Matching) + Rolling Hash


// Approach :: First generate all the divisors of n(it is size of divisors) , one each divsors we have to check is it sortable by doing rotation matching through KMP and all .

class Solution {
public:
    vector<int> allDivisors(int n){
        vector<int> divisors;

        for(int i = 1;i*i<=n;i++){
            if(n % i == 0){
                divisors.push_back(i);
                if(i!=(n/i)) divisors.push_back(n/i);
            }
        }

        return divisors;
    }
    bool rotationMatch(vector<int>&nums, vector<int>& sorted, int start, int k){

        vector<int> pattern(k) , text(2*k);

        for(int i = 0; i < k ; i++){
            pattern[i] = sorted[start+i];
            text[i] = nums[start+i];
            text[i+k] = nums[start+i];
        }

        
        
        vector<int> lps(k,0);

        for(int i = 1 , j = 0 ; i < k ;){

            if(pattern[i] == pattern[j]){
                lps[i++] = ++j;
            }else if(j){
                j = lps[j-1];
            }else{
                lps[i++] = 0;
            }
        }

        for(int i = 0,j = 0; i<2*k;){
            if(text[i] == pattern[j]){
                i++;
                j++;
                if(j == k) return true;
            }else if(j){
                j = lps[j-1];
            }else{
                i++;
            }
        }

        return false;
        
    }
    bool isSortable(int divisor, vector<int>& nums,vector<int>& sorted){
      
        int n = nums.size();
        
        for(int i = 0 ; i < n ;i+=divisor){
    
            if(!rotationMatch(nums,sorted,i,divisor)) return false;
        }

        return true;
        
    }
    int sortableIntegers(vector<int>& nums) {

        int n = nums.size();
        vector<int> divisors = allDivisors(n);
        int ans = 0;
        vector<int> sorted  = nums;
        sort(sorted.begin(),sorted.end());
        for(int &x : divisors){

            if(isSortable(x, nums,sorted)){
                ans+=x;
            }
        }

        return ans;
        
        
    }
};



// Time Complexity : O(NlogN + N*K)
// Space Complexity : O( N)