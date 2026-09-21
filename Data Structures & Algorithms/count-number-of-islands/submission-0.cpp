class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != '1') continue;

                ret++;
                grid[i][j] = '0';

                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    auto p = q.front();
                    q.pop();
                    for (auto [dx, dy] : vector<pair<int, int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
                        int x = p.first + dx;
                        int y = p.second + dy;
                        
                        if (min(x, y) < 0 || x >= n || y >= m || grid[x][y] != '1') continue;
                        grid[x][y] = '0';
                        q.push({x, y});
                    }
                }
            }
        }

        return ret;
    }
};
