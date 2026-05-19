class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                st.push(stoi(tokens[i]));
            }else{
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(tokens[i]=="+") st.push(b+a);
                else if(tokens[i]=="-") st.push(b-a);
                else if(tokens[i]=="*") st.push(b*a);
                else if(tokens[i]=="/") st.push(b/a);
            }
        }
        if(st.empty()) return 1;
        return st.top();
    }
};
