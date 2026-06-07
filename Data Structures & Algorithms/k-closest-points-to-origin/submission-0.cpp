class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        int n = points.size();
        vector<vector<int>> res;

        for(const auto& p: points){
            int x = p[0];
            int y = p[1];
            int dist = (x*x) + (y*y);
            pq.push({dist, {x,y}});
            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
