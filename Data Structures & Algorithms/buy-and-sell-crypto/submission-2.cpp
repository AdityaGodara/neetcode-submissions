class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxPro = 0;
        int mini = prices[0];

        for(int i = 0; i < n; i++){
            int curr = prices[i] - mini;
            maxPro = max(curr, maxPro);
            mini = min(prices[i], mini);
        }

        return maxPro;
    }
};
