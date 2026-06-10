class Solution {
public:
    vector<vector<int>> res;

    void pacificRim(vector<vector<int>>& heights, int i, int j, vector<vector<int>>& grid){
        int n = heights.size();
        int m = heights[0].size();
        if(grid[i][j] == 1) return;
        grid[i][j] = 1;

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        for(int k=0; k<4; k++){
            int rr = i+dr[k];
            int cc = j+dc[k];
            
            if(rr<0 || cc < 0 || rr>=n || cc>=m || heights[rr][cc] < heights[i][j]) continue;
            pacificRim(heights, rr,cc,grid);
        }
    }

    void atlanticRim(vector<vector<int>>& heights, int i, int j, vector<vector<int>>& grid){
        int n = heights.size();
        int m = heights[0].size();
        if(grid[i][j] == 1){
            res.push_back({i,j});
        }
        if(grid[i][j] == 2) return;
        grid[i][j] = 2;

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        for(int k=0; k<4; k++){
            int rr = i+dr[k];
            int cc = j+dc[k];
            
            if(rr<0 || cc < 0 || rr>=n || cc>=m || heights[rr][cc] < heights[i][j]) continue;
            atlanticRim(heights, rr,cc,grid);
            
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        if(n==0) return {};
        int m = heights[0].size();
        vector<vector<int>> grid(n, vector<int>(m,0)); //stroing cell is pacific(1) or atalntic(2)

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0){
                    pacificRim(heights,i,j,grid);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==n-1 || j==m-1){
                    atlanticRim(heights,i,j,grid);
                }
            }
        }

        return res;
    }
};
