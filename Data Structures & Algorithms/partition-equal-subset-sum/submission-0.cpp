class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;

        int x = sum / 2;
        vector<bool> dp(x + 1);
        dp[0] = true;
        for (int i : nums) {
            for (int j = x - i; j >= 0; j--) {
                if (dp[j]) {
                    dp[j + i] = true;
                }
            }
        }

        return dp[x];
    }
};
