class Solution {
  public:
    int gcd(int a, int b) {
        for(int i = min(a,b);i>=1;i--){
            if(a%i == 0 && b%i==0) return i;
        }
        return 1;
    }
};
// Time Complexity : O(min(a,b))
// Space Complexity : O(1)

// Euclidean Algorithm
class Solution {
  public:
    int gcd(int a, int b) {
        while(a>0 && b>0){
            a > b ? a = a%b : b = b%a;
        }
        return (a==0) ? b : a;
    }
};
// Time Complexity: O(log(min(a,b)))
// Space Complxity : O(1)