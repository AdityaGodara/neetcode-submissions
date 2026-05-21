class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> helpStack;
        vector<int> res(temperatures.size(),0);

        for(int i = temperatures.size()-1; i>=0; i--){

            while(!helpStack.empty() && temperatures[helpStack.top()] <= temperatures[i]){
                helpStack.pop();
            }

            if(!helpStack.empty()){
                res[i] = helpStack.top()-i;
            }

            helpStack.push(i);
        }

        return res;
    }
};
