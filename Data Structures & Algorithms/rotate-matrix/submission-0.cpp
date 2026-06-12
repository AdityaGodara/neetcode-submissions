class Solution {
public:

    void verticalRev(vector<vector<int>>& matrix, int n){
        int top = 0;
        int bott = n-1;

        while(top < bott){
            for(int i=0; i<n; i++){
                swap(matrix[top][i], matrix[bott][i]);
            }
            top++;
            bott--;
        }
    }

    void transpose(vector<vector<int>>& matrix, int n){
        vector<pair<int,int>> tracker;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
                tracker.push_back({i,j});
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        verticalRev(matrix, n);
        transpose(matrix, n);
    }
};
