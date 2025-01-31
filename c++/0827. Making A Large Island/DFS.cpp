class Solution {
public:
    vector<int> dir={-1,0,1,0,-1};
    int largestIsland(vector<vector<int>>& grid) {
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
        if(zeroCnt<=1)
            return n*n;

        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int count=1;
                    unordered_set<int> hash;
                    for(int d=0;d<4;d++){
                        int nx=i+dir[d], ny=j+dir[d+1];
                        if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]!=0){
                            if(!hash.count(grid[nx][ny])){
                                count+=islandSize[grid[nx][ny]];
                                hash.insert(grid[nx][ny]);
                            }
                        }
                    }
                    res=max(res,count);
                }
            }
        }
        return res;

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
