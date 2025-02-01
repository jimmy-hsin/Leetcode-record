class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> islandSize = {0, 0};    
        int zeroCnt = 0;   

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {   
                    int count = dfs(grid, i, j, islandSize.size(), n); 
                    islandSize.push_back(count);    
                } else if (grid[i][j] <= 0 ) {
                    zeroCnt++;
                }
            }
        }

        if (zeroCnt <=1 ) return n * n; // 如果全是 1
        if (islandSize.size() <= 3) return islandSize.back() + 1;  

        // 嘗試連接
        int ans = 0;
        vector<bool> visited(islandSize.size(), false);
        vector<int> extent(4, 0);
        int merge, x, y;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1) continue;  // 只檢查 -1（靠近陸地的海水）

                merge = 1;
                for (int d = 0; d < 4; d++) {
                    x = i + dir[d], y = j + dir[d+1];
                    extent[d] = (x >= 0 && x < n && y >= 0 && y < n) ? grid[x][y] : 0;
                    if(extent[d]==-1)
                        extent[d]=0;
                }

                for (int d = 0; d < 4; d++) {
                    if (!visited[extent[d]]) {
                        visited[extent[d]] = true;
                        merge += islandSize[extent[d]];
                    }
                }

                for (int d = 0; d < 4; d++) visited[extent[d]] = false;

                ans = max(ans, merge);
            }
        }

        return ans;
    }

    int dfs(vector<vector<int>>& grid, int x, int y, int ID, int n) {
        if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] > 1) return 0;
        if (grid[x][y] <= 0) { 
            grid[x][y] = -1;  // 標記靠近陸地的水域
            return 0;
        }

        int count = 1;
        grid[x][y] = ID;
        for (int i = 0; i < 4; i++) {
            count += dfs(grid, x + dir[i], y + dir[i+1], ID, n);
        }
        return count;
    }
};
