class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i < n; i++){
            if(matrix[i][0] <= target && target <= matrix[i][m-1]){
                int l = 0;
                int r = m;
                while(l<r){
                    int mid = (l+r)/2;
                    if(matrix[i][mid]==target) return true;
                    else if(matrix[i][mid] < target) l = mid+1;
                    else r = mid;
                }
            }
        }

        return false;
    }
};
