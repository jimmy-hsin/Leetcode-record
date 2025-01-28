class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]!=0)
                    res=max(res,dfs(grid,i,j));
        return res;
    }
    vector<int> dir={-1,0,1,0,-1};
    int dfs(vector<vector<int>>& grid, int x, int y){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]==0)
            return 0;
        int count=grid[x][y];
        grid[x][y]=0;
        for(int d=0;d<4;d++)
            count+=dfs(grid, x+dir[d], y+dir[d+1]);
        return count;
    }
};
