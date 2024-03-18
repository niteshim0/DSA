/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
  const swap = (arr, first, second) => {
     let temp = arr[first];
     arr[first] = arr[second];
     arr[second] = temp;
 };

 const cyclicSort = (arr) => {
     let i = 0;
     let n = arr.length;
     while (i < n) {
         let correctIdx = arr[i]-1;
         if (arr[i] === arr[correctIdx]) {
             i++;
         } else {
             swap(arr, i, correctIdx);
         }
     }
 };
 let ans = [];
 cyclicSort(nums);
 let n = nums.length;
 for (let i = 0; i < n; i++) {
     if (nums[i] !== i+1) {
         ans.push(nums[i]);
     }
 }
 return ans;
};