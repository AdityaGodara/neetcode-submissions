class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<int> res(n+m, 0);

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int mul = (num1[i]-'0')*(num2[j]-'0');

                int p1 = i+j;
                int p2 = i+j+1;

                int sum = mul + res[p2];

                res[p2] = sum%10;
                res[p1] += sum/10;
            }
        }

        string ans = "";
        int idx = 0;
        while(idx <= (n+m)){
            if(idx==n+m) return "0";
            else if(res[idx] != 0) break;
            idx++;
        }

        for(int i=idx; i<n+m; i++){
            ans+= to_string(res[i]);
        }

        return ans;
    }
};
