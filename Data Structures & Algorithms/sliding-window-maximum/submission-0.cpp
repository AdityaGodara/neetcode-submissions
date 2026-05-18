class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;

        for(int i = 0; i <= n-k; i++){
            int lmax = nums[i];
            int right = i;
            while(right < i+k){
                lmax = max(lmax, nums[right]);
                right++;
            }
            res.push_back(lmax);
        }

        return res;
    }
};
