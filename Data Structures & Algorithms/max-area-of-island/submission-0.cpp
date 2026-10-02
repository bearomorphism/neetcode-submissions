class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                ret = max(ret, dfs(i, j, grid));
            }
        }
        
        return ret;
    }
private:
    int dfs(int i, int j, vector<vector<int>> &grid) {
        if (min(i, j) < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) return 0;
        grid[i][j] = 0;

        int ret = 1;
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        for (int d = 0; d < 4; d++) {
            int x = i + dx[d];
            int y = j + dy[d];
            ret += dfs(x, y, grid);
        }

        return ret;
    }
};
