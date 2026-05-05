class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";

        for(char c: s){
            if(isalnum(c)){
                clean += tolower(c);
            }
        }

        string temp = clean;
        reverse(temp.begin(), temp.end());

        if(temp == clean) return true;
        return false;
    }
};
