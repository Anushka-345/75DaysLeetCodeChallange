class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> answer(n, 0);
        stack<int> st; // store indices
        
        for(int i = n-1; i >= 0; i--) {
            int count = 0;
            while(!st.empty() && heights[i] > heights[st.top()]) {
                st.pop();
                count++;
            }
            if(!st.empty()) count++; // first taller person
            answer[i] = count;
            st.push(i);
        }
        
        return answer;
    }
};