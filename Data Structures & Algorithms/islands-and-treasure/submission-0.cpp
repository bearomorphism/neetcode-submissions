class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) v.push_back({i, j});
            }
        }

        int dist = 1;
        const array<pair<int, int>, 4> dir = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};

        while (!v.empty()) {
            vector<pair<int, int>> v2;
            for (auto [i, j] : v) {
                for (auto [dx, dy] : dir) {
                    int x = i + dx;
                    int y = j + dy;
                    if (min(x, y) < 0 || x >= n || y >= m || grid[x][y] != INT_MAX) continue;
                    
                    grid[x][y] = dist;
                    v2.push_back({x, y});
                }
            }

            dist++;
            v.swap(v2);
        }
    }
};
