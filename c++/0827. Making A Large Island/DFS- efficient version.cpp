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
        vector<int> extent(4,0);    //存取四個方向的島嶼ID
        int merge, x, y; //merge用來存取連接後的島嶼面積，x, y 為延伸出去後的新座標
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) continue;
                merge=1;
                //讀取四個方向的島嶼ID
                for(int d=0;d<4;d++){
                    x=i+dir[d], y=j+dir[d+1];
                    extent[d]=0;    //如果出界的話島嶼ID為0(海水也為0，不過這是下面的判斷式操作的)
                    if(x>=0 && x<n && y>=0 && y<n)  extent[d]=grid[x][y];
                }
                //排除重複計算的情況
                for(int d=0;d<4;d++)
                    if(!visited[extent[d]]){
                        visited[extent[d]]=true;
                        merge+=islandSize[extent[d]];
                    }
                //恢復visited的原始狀態
                for(int d=0;d<4;d++)
                    visited[extent[d]]=false;
                ans = max(ans, merge);
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
