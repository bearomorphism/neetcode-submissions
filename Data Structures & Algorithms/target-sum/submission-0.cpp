class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        for (int i : nums) {
            unordered_map<int, int> cnt2;
            for (auto [k, v] : cnt) {
                cnt2[k + i] += v;
                cnt2[k - i] += v;
            }

            cnt = cnt2;
        }

        return cnt[target];
    }
};
