class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() <2) return nums[0];

        vector<int> total_loot(nums.size());
        total_loot[0] = nums[0];
        total_loot[1] = max(nums[0], nums[1]);

        for(int i=2; i< nums.size(); i++){
            total_loot[i] = max(total_loot[i-2]+nums[i], total_loot[i-1]);
        }

        return total_loot[nums.size()-1];
    }
};
