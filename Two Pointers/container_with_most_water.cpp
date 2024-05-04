class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end   = height.size()-1;
        int maxi = INT_MIN;
        while(start<end)
        {
            int breadth = end-start;
            int ht = min(height[start],height[end]);
            int area = breadth*ht;
            if(area>maxi)
            {
                maxi = area;
            }
            if(height[start]>height[end])
            {
                end--;
            }
            else{
                start++;
            }
        }
        return maxi;
    }
};