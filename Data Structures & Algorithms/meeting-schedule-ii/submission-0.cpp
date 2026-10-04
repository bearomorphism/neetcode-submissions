/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (const auto &a, const auto &b) {
            return a.start < b.start;
        });

        int ret = 0;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (const Interval &i : intervals) {
            while (!pq.empty() && i.start >= pq.top()) {
                pq.pop();
            }
    
            pq.push(i.end);
            ret = max<int>(ret, pq.size());
            // cout << pq.top() << ' ' << pq.size() << '\n';
        }

        return ret;
    }
};
