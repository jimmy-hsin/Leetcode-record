class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int computers=0;
        //我們設置兩個vector，用來統計每一行、每一列各有多少電腦，同時記錄現有電腦的總數
        vector<int> row(m,0);
        vector<int> col(n,0);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1){
                    computers++;
                    row[i]++;
                    col[j]++;
                }
        //然後我們再來找找看孤立電腦有多少個
        int lonely=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1 && row[i]==1 && col[j]==1)    //孤立電腦就是他所在的那一行及那一列都只有他自己
                    lonely++;
        
        return computers-lonely;    //把所有電腦的總數減去孤立電腦的數量就是答案
    }
};
