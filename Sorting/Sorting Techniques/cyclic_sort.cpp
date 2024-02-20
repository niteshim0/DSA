 void cyclicSort(vector<int>&arr){
        int i = 0;
        while(i<arr.size()){
            int correctIdx = arr[i];
            if(correctIdx == arr.size()){
                i++; // out of bound chala jayega isse nahi rakh sakte
            }else if(arr[i]!=arr[correctIdx] && correctIdx!=arr.size()){
                 int temp  = arr[i];
                 arr[i] = arr[correctIdx];
                 arr[correctIdx] = temp;
            }else{
                i++;
            }
        }
}