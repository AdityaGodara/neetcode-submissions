class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                int lvl = min(heights[i], heights[j]);
                int curr = lvl*(j-i);
                res = max(curr, res);
            }
        }

        return res;
    }
};
