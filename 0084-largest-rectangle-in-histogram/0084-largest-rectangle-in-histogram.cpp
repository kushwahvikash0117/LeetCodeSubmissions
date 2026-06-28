class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0, nse, pse, el;
        for(int i=0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                el = st.top();
                st.pop();
                nse = i; 
                pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, heights[el] * (nse - pse - 1));
            }
            st.push(i);
        }
        while(!st.empty()){
            nse = heights.size();
            el = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[el] * (nse - pse - 1));
        }
        return maxArea;
    }
};