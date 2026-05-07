class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                res = max(min(heights[i],heights[j])*(j-i), res);
            }
        }

        return res;
    }
};
