// Replace with XOR of Adjacent
// Concept :: Traversal + Element Forwarding


class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        
        int n = arr.size();
        
        int temp1 = arr[1];
        int temp2 = arr[n-2];
        
        int prev = arr[0];
        
        for(int i = 1 ; i < n - 1 ; i++){
            
            int temp = arr[i];
            arr[i] = prev^arr[i+1];
            prev = temp;
            
        }
        
        arr[0] = arr[0]^temp1;
        arr[n-1] = temp2^arr[n-1];
        
        return ;
    }
};