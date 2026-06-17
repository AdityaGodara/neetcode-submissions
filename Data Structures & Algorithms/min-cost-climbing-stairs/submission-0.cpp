class Solution {
public:

    int solve(int idx, vector<int>& cost, vector<int>& track){
        int n = cost.size();
        if(idx >= n) return 0;

        if(track[idx] != -1) return track[idx];

        int a = cost[idx] + solve(idx+1, cost, track);
        int b = cost[idx] + solve(idx+2, cost, track);

        track[idx] =  min(a,b);
        return track[idx];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> track(101, -1);
        return min(solve(0, cost, track), solve(1, cost, track));
    }
};
