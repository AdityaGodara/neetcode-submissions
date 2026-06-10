class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return -1;
        int m = grid[0].size();
        if (m == 0) return -1;

        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) q.emplace(i, j);
            }
        }

        int minute = 0;
        while (!q.empty()) {
            int sz = q.size();
            bool change = false;

            while (sz--) {
                int r_row = q.front().first;
                int r_col = q.front().second;
                q.pop();

                for (auto [dr, dc] : dirs) {
                    int x = r_row + dr;
                    int y = r_col + dc;

                    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != 1) continue;
                    grid[x][y] = 2;
                    q.emplace(x, y);
                    change = true;
                }
            }
            if (change) minute++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return minute;
    }
};
