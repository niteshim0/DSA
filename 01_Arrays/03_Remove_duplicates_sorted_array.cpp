// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

/*Brute Force : - Store all the elements of array into a set.
                - Itrate the set and put the unique elements.*/

int removeDuplicates(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        int index  = 0;
        for(auto it : st){
            nums[index] = it;
            index++;
        }
        return index;
}

/*Optimal Approach : - Use two pointerss one starts at first index , one at immediate next.
                     - Check for duplicacy if duplicate move the j pointer.
                     - If not duplicate move the i pointer and update it with unique element.*/
                     
int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        for(int j = 1;j<n;j++){
            if(arr[j]!=arr[i]){
                arr[++i] = arr[j];
            }
        }
        return i+1;
}