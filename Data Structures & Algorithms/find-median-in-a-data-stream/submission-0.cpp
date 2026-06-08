class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int count;

public:
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        pq.push(num);
        count++;
    }
    
    double findMedian() {
        vector<int> temp;
        if(count % 2 == 1){
            
            int res;
            int n = (count+1)/2;
            for(int i=0; i<n-1; i++){
                temp.push_back(pq.top());
                pq.pop();
                count--;
            }
            res = (double) pq.top();
            for(int i : temp){
                pq.push(i);
                count++;
            }
            return res;
        }else{

            int n = count/2;
            for(int i=0; i<n-1; i++){
                temp.push_back(pq.top());
                pq.pop();
                count--;
            }
            int n1 = pq.top();
            temp.push_back(n1);
            pq.pop();
            count--;
            int n2 = pq.top();

            for(int i : temp){
                pq.push(i);
                count++;
            }
            return (double)(n1+n2)/2;
        }
    }
};
