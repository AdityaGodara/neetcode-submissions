class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas = 0, sumCost = 0;
        for(int i=0; i< gas.size(); i++){
            sumGas += gas[i];
            sumCost += cost[i];
        }
        if(sumGas < sumCost) return -1;

        int start = 0;
        int currGas = 0;
        for(int i=0; i< gas.size(); i++){
            currGas = currGas + gas[i] - cost[i];
            if(currGas < 0) {
                currGas = 0;
                start = i+1;
            }
        }

        return start;
    }
};
