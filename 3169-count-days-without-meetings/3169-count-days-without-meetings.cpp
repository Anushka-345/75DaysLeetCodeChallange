class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int covered = 0;

        int start = meetings[0][0];
        int end = meetings[0][1];

        for (int i = 1; i < meetings.size(); i++) {
            int s = meetings[i][0];
            int e = meetings[i][1];

            if (s <= end) {
                // overlap → merge
                end = max(end, e);
            } else {
                // add previous interval
                covered += (end - start + 1);

                // move to new interval
                start = s;
                end = e;
            }
        }

        // add last interval
        covered += (end - start + 1);

        return days - covered;
    }
};