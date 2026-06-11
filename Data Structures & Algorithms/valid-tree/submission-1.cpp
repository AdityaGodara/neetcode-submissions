class Solution {
public:

    void dfs(int src, vector<bool>& vis, vector<vector<int>>& edges){
        vis[src] = true;

        for(auto &ed: edges){
            int neigh = -1;

            if(ed[0]==src){
                neigh = ed[1];
            }else if(ed[1]==src){
                neigh = ed[0];
            }else continue;

            if(!vis[neigh]){
                dfs(neigh, vis,edges);
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;

        vector<bool> vis(n, false);
        dfs(0, vis,edges);

        for(int i=0; i< n; i++){
            if(!vis[i]) return false;
        }

        return true;
    }
};
