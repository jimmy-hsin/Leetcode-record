class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    int largestIsland(vector<vector<int>>& grid) {
        // 第一步，只填號
        int n=grid.size();
        vector<int> islandSize={0,0};    
        int zeroCnt=0;   
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){   
                    int count=dfs(grid, i, j, islandSize.size(), n); 
                    islandSize.push_back(count);    
                }
                else if(grid[i][j]==0)
                    zeroCnt++;
            }
        }
        if(zeroCnt<=1)    //如果0的總個數<=1，代表轉化後就沒有0了
            return n*n;
        if(islandSize.size()<=3)    return islandSize.back() + 1;    
        
        // 嘗試連接
        //因為只有四個方向，所以用一個全域變數做操作 會比一直新建區域變數來的快
        int ans = 0;
        vector<bool> visited(islandSize.size(), false);
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
                merge = 1 + islandSize[up];
            //確認沒有重複計算
                if (!visited[down]) {
                    visited[down] = true;
                    merge += islandSize[down];
                }
                if (!visited[left]) {
                    visited[left] = true;
                    merge += islandSize[left];
                }
                if (!visited[right]) {
                    visited[right] = true;
                    merge += islandSize[right];
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

    int dfs(vector<vector<int>>& grid, int x, int y, int ID, int n){
        if(x<0 || y<0 || x>=n || y>=n || grid[x][y]!=1)    
            return 0;
        int count=1;
        grid[x][y]=ID;        
        for(int i=0;i<4;i++)
            count+=dfs(grid,x+dir[i],y+dir[i+1], ID, n);    
        return count;
    }
};
