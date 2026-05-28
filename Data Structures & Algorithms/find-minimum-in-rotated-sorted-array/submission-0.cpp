class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n-1, mini = INT_MAX;

        while(l<=r){
            int mid = (l+r)/2;
            if(nums[l] <= nums[mid]){
                mini = min(nums[l], mini);
                l = mid+1;
            }else{
                mini = min(nums[r], mini);
                r = mid;
            }
        }

        return mini;
    }
};
