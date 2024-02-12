# Arrays

## Booyer-Moore Merge Voting Algorithm

- finds out the element which occurs n/2 times in an array.
- operates on the fact that majority element will be always more than one than other elements in an array.

```cpp
int majorityElement(vector<int>& nums) {
       int cnt = 0;
       int ans = 0;
       for(int &x : nums){
           if(cnt == 0){
               cnt = 1;
               ans = x;
           }else{
               if(ans == x){
                   cnt+=1;
               }else{
                   cnt-=1;
               }
           }
       }
       return ans;
}
```