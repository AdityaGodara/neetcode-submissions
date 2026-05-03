class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(string x : strs){
            s+=x;
            s.push_back('-');
    }

        return s;
    }

    vector<string> decode(string s) {
        string temp = "";
        vector<string> res;

        for(int i = 0; i < s.length(); i++){
            if(s[i] != '-'){
                temp.push_back(s[i]);
            }
            else{
                res.push_back(temp);
                temp = "";
            }
        }

        return res;
    }
};
