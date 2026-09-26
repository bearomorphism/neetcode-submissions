class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> pq;
        unordered_map<int, int> cnt;
        for (int i = 0; i < k; i++) {
            if (cnt[nums[i]] == 0) {
                pq.push(nums[i]);
            }
            cnt[nums[i]]++;
        }

        vector<int> ret;
        ret.push_back(pq.top());
        for (int i = k; i < nums.size(); i++) {
            if (cnt[nums[i]] == 0) {
                pq.push(nums[i]);
            }
            cnt[nums[i]]++;
            cnt[nums[i - k]]--;
            while (cnt[pq.top()] == 0) {
                pq.pop();
            }

            ret.push_back(pq.top());
        }

        return ret;
    }
};
