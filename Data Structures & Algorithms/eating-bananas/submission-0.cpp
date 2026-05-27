class Solution {
public:

    int computeTime(vector<int>& arr, int rate){
        int time = 0;
        for(int i = 0; i<arr.size(); i++){
            time += ceil((double)arr[i]/rate);
        }
        return time;
    }

    int findMax(vector<int>& arr){
        int maxi = INT_MIN;
        for(int x : arr){
        maxi = max(maxi, x);
            }
        return maxi;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max = findMax(piles);
        int l = 1;
        int r = max;
        int ans = INT_MAX;
        while(l <= r){
            int mid = (l+r)/2;
            int timeReq = computeTime(piles, mid);
            if(timeReq > h) l = mid+1;
            else if(timeReq <= h){
                ans = min(ans, mid);
                r = mid-1;
            }
        }

        return ans;
    }
};
