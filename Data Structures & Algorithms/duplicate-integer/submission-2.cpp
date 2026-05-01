class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for(int x : nums){
            mpp[x]++;
        }

        for(auto const& [key, val]: mpp){
            if(val > 1) return true;
        }

        return false;
    }
};