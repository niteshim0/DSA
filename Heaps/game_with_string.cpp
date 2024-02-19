class Solution{
public:
    int minValue(string s, int k){
        // code here
        int n = s.size();
        priority_queue<int> maxHeap;
        vector<int> hash(26,0);
        for(int i = 0;i<n;i++){
            hash[s[i]-'a']++;
        }
        for(int i = 0;i<26;i++){
            if(hash[i]!=0) maxHeap.push(hash[i]);
        }
        while(k>0){
           int val = maxHeap.top();
           maxHeap.pop();
           val-=1;
           k-=1;
           maxHeap.push(val);
        }
        int sum = 0;
        while(!maxHeap.empty()){
            int tp = maxHeap.top();
            sum+=(tp*tp);
            maxHeap.pop();
        }
        return sum;
    }
    
};