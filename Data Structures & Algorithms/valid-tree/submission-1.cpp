class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        
        vector<vector<int>> g(n);
        for (const auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n);
        vis[0] = true;
        int cnt = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int x = q.front();
            cnt++;
            // cout << x << '\n';
            q.pop();
            for (int i : g[x]) {
                if (vis[i]) continue;
                vis[i] = true;
                q.push(i);
            }
        }

        // cout << cnt << '\n';

        return cnt == n;
    }
};
