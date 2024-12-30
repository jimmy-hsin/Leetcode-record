class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int count=0;
        for(int j=0;j<n;j++){
            for(int i=1;i<m;i++){
                int temp=max(grid[i-1][j]+1, grid[i][j]);
                count+=temp-grid[i][j];
                grid[i][j]=temp;
            }
        }
        return count;
    }
};
