class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    int largestIsland(vector<vector<int>>& grid) {
        // 第一步，只填號
        int n = grid.size();
        int id= 2;  //ID從2開始
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j]==1)
                    dfs(grid, n, i, j, id++);
            }
        }

        // 第二步，統計每個島嶼的大小
        int ans = 0;
        vector<int> areas(id,0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] <= 1) 
                    continue;
                else 
                    areas[grid[i][j]]++;
                ans = max(ans, areas[grid[i][j]]);
            }
        }
        if(areas.size()<=3)    return areas.back() + 1;
        
        // 嘗試連接
        //因為只有四個方向，所以用一個全域變數做操作會比一直新建區域變數來的快
        vector<bool> visited(id, false);
        int up, down, left, right, merge;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) continue;
            //取出四個方向的島嶼ID
                up = (i > 0) ? grid[i-1][j] : 0;
                down = (i < n-1) ? grid[i+1][j] : 0;
                left = (j > 0) ? grid[i][j-1] : 0;
                right = (j < n-1) ? grid[i][j+1] : 0;
                
                visited[up] = true;
                merge = 1 + areas[up];
            //確認沒有重複計算
                if (!visited[down]) {
                    visited[down] = true;
                    merge += areas[down];
                }
                if (!visited[left]) {
                    visited[left] = true;
                    merge += areas[left];
                }
                if (!visited[right]) {
                    visited[right] = true;
                    merge += areas[right];
                }
                ans = max(ans, merge);
                visited[up] = false;
                visited[down] = false;
                visited[left] = false;
                visited[right] = false;
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& grid, int n, int i, int j, int id) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) return; //出界，或不是陸地，或為已經探訪過的陸地

        grid[i][j] = id;
        for(int d=0;d<4;d++)
            dfs(grid, n, i+dir[d], j+dir[d+1], id);
    }
};
