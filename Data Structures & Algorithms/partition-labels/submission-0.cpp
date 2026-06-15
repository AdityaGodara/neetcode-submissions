class Solution {
   public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mpp;
        int last_max = 0;
        int currCount = 0;
        vector<int> res;

        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]] = i;
        }

        for (int i = 0; i < s.size(); i++) {
            last_max = max(last_max, mpp[s[i]]);
            currCount++;
            if(i == last_max){
                res.push_back(currCount);
                currCount = 0;
            }
        }

        return res;
    }
};
