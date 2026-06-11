class Solution {
public:

    void bfs(int src, vector<bool>& vis, vector<vector<int>>& edges){
        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int u = q.front();
            q.pop();
            vis[u] = true;

            for(auto& ed: edges){
                int neigh = -1;
                if(ed[0] == u) neigh = ed[1];
                else if(ed[1]==u) neigh = ed[0];
                else continue;

                if(!vis[neigh]){
                    q.push(neigh);
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        int res = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                res++;
                bfs(i, vis, edges);
            }
        }

        return res;
    }
};
