class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> st;

        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int ele = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                int currArea = heights[ele]*(nse-pse-1);
                maxArea = max(currArea, maxArea);
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = heights.size();
            int ele = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, heights[ele]*(nse-pse-1));
        }

        return maxArea;
    }
};
