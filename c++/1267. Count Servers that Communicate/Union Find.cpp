class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int computers=0;
        vector<int> row(m,0);
        vector<int> col(n,0);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1){
                    computers++;
                    row[i]++;
                    col[j]++;
                }
        
        int lonely=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1 && row[i]==1 && col[j]==1)
                    lonely++;
        
        return computers-lonely;
    }
};
