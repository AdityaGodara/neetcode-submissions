class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        vector<int> res;

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int needed = target - num;

            if(mpp.find(needed) != mpp.end()){
                return {mpp[needed], i};
            }

            mpp[num] = i;
        }

        return {-1,-1};
    }
};
