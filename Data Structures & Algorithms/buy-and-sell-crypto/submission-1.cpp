class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxPro = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(prices[j]-prices[i] > 0){
                    maxPro = max(maxPro, prices[j]-prices[i]);
                }
            }
        }

        return maxPro;
    }
};
