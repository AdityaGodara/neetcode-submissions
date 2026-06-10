class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0) return;
        int m = grid[0].size();
        if(m==0) return;

        queue<pair<int,int>> q;
        vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){

                if(grid[i][j] == 0 ) q.emplace(i,j);
            }
        }

        while(!q.empty()){
            int t_row = q.front().first;
            int t_col = q.front().second;
            q.pop();

            for(auto dir: dirs){
                int x = t_row+dir.first;
                int y = t_col+dir.second;

                if(x<0 || y<0 || x>= n || y>=m || grid[x][y]!=2147483647) continue;

                grid[x][y] = grid[t_row][t_col]+1;
                q.emplace(x,y);
            }
        }
    }
};
