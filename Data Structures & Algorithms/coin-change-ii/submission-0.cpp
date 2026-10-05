class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int i : coins) {
            for (int j = 0; j < amount; j++) {
                int x = i + j;
                if (x <= amount) {
                    dp[x] += dp[j];
                }
            }
        }

        return dp[amount];
    }
};
