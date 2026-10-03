class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size()-1;
        int max_area = 0;
        while(i < j) {
            int area = min(heights[i], heights[j]) * (j - i);
            if(area > max_area) max_area = area;
            if(heights[i] < heights[j]) i++;
            else j--;
        }
        return max_area;
    }
};
