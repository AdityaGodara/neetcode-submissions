class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mpp;
        int n = strs.size();
        if(n == 1) return {strs};

        for(string s : strs){
            string key = s;
            sort(key.begin(), key.end());

            mpp[key].push_back(s);
        }

        for(auto const& [key, val]: mpp){
            res.push_back(val);
        }

        return res;
    }
};
