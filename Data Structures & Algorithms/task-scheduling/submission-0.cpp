class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mpp(26, 0);
        priority_queue<int> pq;
        for (auto c : tasks) {
            mpp[c - 'A']++;
        }

        for (auto it : mpp) {
            if (it > 0) {
                pq.push(it);
            }
        }

        int result = 0;
        while (!pq.empty()) {
            int time = 0;
            int cycle = n + 1;
            vector<int> temp;

            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    int maxEle = pq.top();
                    pq.pop();
                    if (maxEle > 1) temp.push_back(maxEle - 1);
                    time++;
                }
            }

            for (auto count : temp) {
                pq.push(count);
            }
            if (pq.empty()) {
                result += time;
            } else {
                result += cycle;
            }
        }

        return result;
    }
};
