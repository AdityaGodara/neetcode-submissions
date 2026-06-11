class DSU{
    public:
        vector<int> parent;
        vector<int> rank;

        DSU(int n){
            parent.resize(n+1);
            rank.resize(n+1);
            for(int i=0; i<n; i++){
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int find(int x){
            if(x == parent[x]){
                return x;
            }
            return parent[x] = find(parent[x]);
        }
        void Union(int x, int y){
            int x_par = find(x);
            int y_par = find(y);

            if(x_par == y_par) return;

            if(rank[x_par] > rank[y_par]){
                parent[y_par] = x_par;
            }else if(rank[y_par] > rank[x_par]){
                parent[x_par] = y_par;
            }else{
                parent[x_par] = y_par; //WE made y as parent of x
                rank[y_par]++;
            }
        }
};

class Solution {
public:


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n =edges.size();

        DSU dsu(n);

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            if(dsu.find(u) == dsu.find(v)) return edge;
            dsu.Union(u,v);
        }

        return {};
    }
};
