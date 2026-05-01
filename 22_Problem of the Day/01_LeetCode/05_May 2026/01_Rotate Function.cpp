// LC 396. Rotate Function
// https://leetcode.com/problems/rotate-function/description

// Concepts :: Dynamic Programming + Recurrence Relation + Mathematical Induction

// Approach I : Brute Force
// We will rotate once for every element , and calculate the updated sum
// it will lead to heavy calculations , not feasible solution


class Solution {
public:
    int rotationFunctionSum(vector<int>& req,int n){
        
        int sum = 0;
        
        for(int i = 0 ; i < n ; i++){
            
            int need = i * req[i];
            sum+=need;
        }

        return sum;
    }
    void rotateByOne(vector<int>& arr,int n){
         
        int last = arr[n-1];
        for(int i = 1 ; i < n ; i++){

            arr[n-i] = arr[n-i-1];
        }

        arr[0] = last;
    }
    int maxRotateFunction(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return 0;
        vector<int> req = nums;

        // first no rotation
        int maxi = rotationFunctionSum(req,n);

        for(int i = 1 ; i < n ; i++){
            
            rotateByOne(req,n);
            int need = rotationFunctionSum(req,n);
            maxi = max(maxi,need);       
        }

        return maxi;

    }
};

// Time Complexity : O(N*N)
// Space Complexity : O(N)

// Approach 2 :: Pure Mathematics + Dynamic Programming

// https://leetcode.com/problems/rotate-function/solutions/8120425/solution-by-la_castille-vov3


class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int sum = 0 , F = 0;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            sum+=nums[i];
            F+=(i*nums[i]);
        }

        int maxi = F;
        for(int i = 1 ; i < n ; i++){
            F += sum - n * nums[n-i];
            maxi = max(maxi, F);
        }

        return maxi;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)