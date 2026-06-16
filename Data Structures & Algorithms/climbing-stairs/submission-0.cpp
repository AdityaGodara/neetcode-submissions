class Solution {
public:
    unordered_map<int, int> cache;
    int climbStairs(int n) {
        if(cache.find(n) != cache.end()){
            return cache[n];
        }

        if( n<=1 ){
            cache[n] = n;
            return n;
        }
        if( n==2 ){
            cache[n] = 2;
            return 2;
        }

        int left = climbStairs(n-1);
        int right = climbStairs(n-2);

        cache[n] = left + right;

        return cache[n];
    }
};
