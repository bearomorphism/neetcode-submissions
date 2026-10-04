class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ret;
        
        vector<int> cur = intervals[0];
        for (const auto &i : intervals) {
            if (i[0] <= cur[1]) {
                cur[1] = max(cur[1], i[1]);
            } else {
                ret.push_back(cur);
                cur = i;
            }
        }

        ret.push_back(cur);

        return ret;
    }
};
