class CountSquares {
public:
    unordered_map<int, unordered_map<int,int>> mpp;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        mpp[x][y]++; 
    }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        int totalSq = 0;

        if(mpp[x1].size() == 0) return 0;

        for(auto& entry: mpp[x1]){
            int y2 = entry.first;
            int freq = entry.second;

            if(y1==y2) continue;

            int sideLen = abs(y2-y1);

            totalSq += countSquares(x1,y1, x1+sideLen, y1,y2, freq);
            totalSq += countSquares(x1,y1, x1-sideLen, y1,y2, freq);
        }

        return totalSq;
    }

    int countSquares(int x1, int y1, int x3, int y3, int y2, int count){
        if(mpp.find(x3)==mpp.end()) return 0;

        return count * mpp[x3][y1] * mpp[x3][y2];
    }
};
