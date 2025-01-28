class Solution {
public:
    /*
        基本上這題就是 695. Max Area of Island 的衍伸問題，只是695每個方塊的值為1，這題會有大於1的值，但解法都差不多
    */
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]!=0)    //如果這格有魚
                    res=max(res,dfs(grid,i,j));    //就找找看這個池塘裡可以抓多少，並存取最多魚的池塘的值
        return res;
    }
    vector<int> dir={-1,0,1,0,-1};
    int dfs(vector<vector<int>>& grid, int x, int y){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]==0)    //如果出界，或這格是陸地，就回傳0
            return 0;
        int count=grid[x][y];    //先把這格的魚存起來
        grid[x][y]=0;    //把grid值改為0，以免DFS被重複計算
        for(int d=0;d<4;d++)
            count+=dfs(grid, x+dir[d], y+dir[d+1]);    //看看衍伸出去的區域能抓回多少魚，加進這個魚池的總數量裡
        return count;
    }
};
