class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<pair<int,int>> qPairs;
        vector<int> res(queries.size());

        for(auto& q: queries){
            qPairs.emplace_back(q, qPairs.size());
        }

        sort(qPairs.begin(), qPairs.end());
        sort(intervals.begin(), intervals.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        int j = 0, query, index;
        for(int i = 0; i < queries.size(); i++){
            query = qPairs[i].first;
            index = qPairs[i].second;
            while(j < intervals.size() && intervals[j][0] <= query){
                pq.push({intervals[j][1] - intervals[j][0] + 1, intervals[j][1]});
                ++j;
            }
            while(!pq.empty() && pq.top().second < query) pq.pop();

            res[index] = pq.empty() ? -1 : pq.top().first;
        }

        return res;
    }
};
