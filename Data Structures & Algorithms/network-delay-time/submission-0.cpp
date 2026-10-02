class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n); // to, weight

        for (const auto &v : times) {
            g[v[0] - 1].push_back({v[1] - 1, v[2]});
        }

        vector<int> dp(n, INT_MAX);
        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<P>> pq; // time, idx
        pq.push({0, k - 1});
        while (!pq.empty()) {
            auto [t, from] = pq.top();
            pq.pop();
            
            if (dp[from] != INT_MAX) continue;
            dp[from] = t;
            for (auto [to, w] : g[from]) {
                int x = t + w;
                if (dp[to] != INT_MAX) continue;
                pq.push({x, to});
            }
        }

        // for (int i : dp) {
        //     cout << i << ' ';
        // }

        int ret = *max_element(dp.begin(), dp.end());
        return ret == INT_MAX ? -1 : ret;
    }
};
