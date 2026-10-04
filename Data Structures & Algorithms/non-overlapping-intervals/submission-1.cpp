class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int ret = 0;
        int prevEnd = INT_MIN;
        for (const auto &i : intervals) {
            if (i[0] < prevEnd) {
                ret++;
                prevEnd = min(prevEnd, i[1]);
            } else {
                prevEnd = i[1];
            }
        }

        return ret;
    }
};
