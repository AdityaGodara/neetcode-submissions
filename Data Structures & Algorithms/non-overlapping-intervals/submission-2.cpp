class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        int n = intervals.size();
        vector<vector<int>> validInter;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        int last_end = INT_MIN;
        for(int i=0; i<n; i++){
            if(intervals[i][0] >= last_end){
                validInter.push_back(intervals[i]);
                last_end = intervals[i][1];
                res++;
            }
        }
        return n-res;
    }
};
