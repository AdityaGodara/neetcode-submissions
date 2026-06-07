class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int, vector<int>> pq;
        for(int n: stones){
            pq.push(n);
        }

        while(pq.size() > 1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            int diff = first-second;
            if(diff==0) continue;
            else pq.push(abs(diff));
        }

        if(pq.empty()) return 0;
        return pq.top();
    }
};
