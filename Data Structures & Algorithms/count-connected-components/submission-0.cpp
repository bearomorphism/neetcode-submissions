class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (const auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int ret = 0;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            ret++;

            vis[i] = true;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                
                for (int y : g[x]) {
                    if (vis[y]) continue;
                    vis[y] = true;
                    q.push(y);
                }
            }
        }

        return ret;
    }
};
