class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& q) {
        vector<int> res;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        for(int i = 0; i < q.size(); i++){
            int mini = -1;
            int step = 0;
            while(step < intervals.size() && intervals[step][0] <= q[i]){
                int curr = -1;
                if(q[i] <= intervals[step][1]){
                    curr = intervals[step][1] - intervals[step][0] + 1;
                    if(mini == -1) mini = curr;
                    else mini = min(mini, curr);
                }
                step++;
            }
            res.push_back(mini);
        }

        return res;
    }
};
