class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        vector<int> res;
        for(int x : nums){
            counts[x]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto const& [val, freq]: counts){
            pq.push({freq, val});
        }

        while(k>=1){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return res;
    }
};
