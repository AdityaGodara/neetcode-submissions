class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp;
        int left = 0, right = 0, minLen = INT_MAX, sIndex = -1;
        int n = s.size(), m = t.size();
        int count = 0;

        for(char c: t) mpp[c]++;

        while(right < s.size()){
            mpp[s[right]]--;
            if(mpp[s[right]] >= 0){
                count++;
            }
            while(count == m){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    sIndex = left;
                }
                mpp[s[left]]++;
                if(mpp[s[left]] > 0) count-=1;
                left++;
            }
            right++;
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};
