class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mpp;
        int n = numbers.size();
        for(int i = 0; i < n; i++){
            int num = numbers[i];
            int left = target - num;
            if(mpp.find(left) != mpp.end()){
                return {mpp[left]+1, i+1};
            }

            mpp[num] = i;
        }
    }
};
