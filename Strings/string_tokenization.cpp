vector<int> splitString(string &inputString,char delimiter){
       vector<int> tokens;
       istringstream inputStream(inputString);
       string token;
       while (getline(inputStream, token, delimiter)) {
        tokens.push_back(stoi(token));
       }
        return tokens;
}


// complete question
//https://leetcode.com/problems/compare-version-numbers/
/*class Solution {
public:
    vector<int> splitString(string &inputString,char delimiter){
       vector<int> tokens;
       istringstream inputStream(inputString);
       string token;
       while (getline(inputStream, token, delimiter)) {
        tokens.push_back(stoi(token));
       }
        return tokens;
    }
    int compareVersion(string version1, string version2) {
        vector<int> first = splitString(version1,'.');
        vector<int> second = splitString(version2,'.');
        int minSize = min(first.size(),second.size());
        int maxSize = max(first.size(),second.size());
        for(int i = 0;i<maxSize;i++){
           int num1 = i<first.size() ? first[i] : 0;
           int num2 = i<second.size() ? second[i] : 0;
           if(num1>num2) return 1;
           if(num2>num1) return -1;
        }
        return 0;
    }
};*/