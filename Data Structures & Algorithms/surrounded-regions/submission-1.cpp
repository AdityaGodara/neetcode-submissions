class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n==0) return;
        int m = board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dirs = {{1,0},{0,1}, {-1,0},{0,-1}};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j] == 'O'){
                    board[i][j] = '#';
                    q.emplace(i,j);
                }
            }
        }

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x,y] = q.front();
                q.pop();
                for(auto dir: dirs){
                    int nx = x+dir[0];
                    int ny = y+dir[1];

                    if(nx<0 || ny<0 || nx>=n || ny>=m || board[nx][ny] != 'O') continue;
                    board[nx][ny] = '#';
                    q.emplace(nx,ny);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
