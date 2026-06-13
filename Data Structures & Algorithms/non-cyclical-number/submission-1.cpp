class Solution {
public:
    vector<int> track;
    bool isHappy(int n) {
        if(n==1) return true;

        int sum = 0;
        while(n>=1){
            int mod_val = n%10;
            sum += mod_val*mod_val;
            
            n = n/10;
        }
        if(find(track.begin(),track.end(), sum) != track.end()) return false;
        else track.push_back(sum);
        

        return isHappy(sum);
    }
};
