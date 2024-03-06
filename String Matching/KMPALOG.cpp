//https://www.geeksforgeeks.org/problems/search-pattern0205/1
class Solution
{
    public:
        vector <int> KMPSearch(string pattern, string text)
        {
            
            int n = text.size();
            int m = pattern.size();
            vector<int> lps(m);
            int i = 1 , j = 0;
            lps[0] = 0;
            while(i<m){
                if(pattern[i] == pattern[j]){
                    lps[i] = j+1;
                    i++;
                    j++;
                }else{
                    if(j>0){
                        j = lps[j-1];
                    }else{
                        lps[i] = 0;
                        i++;
                    }
                }
            }
            
            vector<int> ans;
            i = 0;
            j = 0;
            while(i<n){
                if(text[i] == pattern[j]){
                    i++;
                    j++;
                    if(j == m){
                        ans.push_back(i-m+1); 
                        j = lps[j-1];
                    }
                }else{
                    if(j>0){
                        j = lps[j-1];
                    }else{
                        i++;
                    }
                }
            }
            
            return ans;
        }
     
};
