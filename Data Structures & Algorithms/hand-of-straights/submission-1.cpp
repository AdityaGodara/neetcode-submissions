class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {    
        multiset<int> ms;
        for(int n: hand){
            ms.insert(n);
        }

        while(ms.size()){
            int item = *ms.begin();
            for(int i=0; i<groupSize; i++){
                if(ms.count(item+i) == 0) return false;
                ms.erase(ms.find(item+i));
            }
        }
        return true;
    }
};
