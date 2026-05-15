class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;
        int left = 0;
        int maxFreq = 0;
        int maxi = 0;

        for(int right = 0; right < s.size(); right++){
            mpp[s[right]]++;

            maxFreq = max(maxFreq, mpp[s[right]]);

            int window = right - left + 1;

            if(window - maxFreq > k){
                mpp[s[left]]--;
                left++;
            }

            maxi = max(maxi, right-left+1);
        }

        return maxi;
    }
};
