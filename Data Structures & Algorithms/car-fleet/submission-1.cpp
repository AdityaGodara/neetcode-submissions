class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        priority_queue<vector<double>> pq;
        for(int i=0 ; i<n ; i++){
            double time = (double)(target-position[i])/speed[i];
            pq.push({(double)position[i], (double)speed[i], time});
        }
        if(pq.size()==0) return 0;
        int res = 0;
        while(true){
            if(pq.size()==1){
                res++;
                break;
            }

            auto ahead = pq.top();
            pq.pop();
            auto behind = pq.top();
            pq.pop();

            if(ahead[2] >= behind[2]) pq.push(ahead);
            else{ 
                res++;
                pq.push(behind);
            }
        }

        return res;
    }
};
