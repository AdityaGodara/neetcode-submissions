class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> res;

        int top = 0, left = 0, right = m - 1, bottom = n - 1;

        while (top <= bottom && left <= right) {
            // right pointer -->
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
             top++;
             
            // down pointer
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;

            // left pointer <--
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // up Pointer ^
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            
        }

        return res;
    }
};
