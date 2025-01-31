class Solution {
public:
    /*
        此題為695. Max Area of Island的延伸，相較於只找最到的島嶼面積，我們現在有一個機會可以把原本是水的格子轉化成陸地，試問，在只有一次轉化機會的狀況下，我們能得到的最大島嶼面積是多少?
    */
    vector<int> dir={-1,0,1,0,-1};
    int largestIsland(vector<vector<int>>& grid) {
        //相較於過去DFS尋找過後就把島嶼的數值轉成0，我們現在使用的DFS是把尋找過後的陸地區塊數值轉成對應的島嶼編號，由於0，1已經被使用了，所以我們的編號從2開始
        int n=grid.size();
        vector<int> islandSize={0,0};    //因為我們要從2開始編號，我們使用的是當前的size來當編號，所以先初始化，
        int zeroCnt=0;    //計算0的個數，以排出一些特殊情況，加速運算
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){    //陸地，且還沒被探詢過
                    int count=dfs(grid, i, j, islandSize.size(), n); //islandSize.size()就是當前需要填的編號
                    islandSize.push_back(count);    //把當前查詢到的島嶼大小加進vector裡
                }
                else if(grid[i][j]==0)
                    zeroCnt++;
            }
        }
        if(zeroCnt<=1)    //如果0的總個數<=1，代表轉化後就沒有0了
            return n*n;
        if(islandSize.size()<=3)    return islandSize.back() + 1;    //如果最後的陣列大小小於3，代表要嘛只有一塊島嶼，要嘛都是海水，所以回傳最後的一塊的大小+1 (可能是海水islandSize[1], 也可能是陸地islandSize[2])

        int res=0;//紀錄轉化後的最大島嶼面積
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){//如果這塊是海水，試試看轉化他的結果為何
                    int count=1;//將它轉化的面積
                    unordered_set<int> hash;//避免重複計算，因為四個方向延伸出去的地方可能是同一塊島嶼
                    for(int d=0;d<4;d++){
                        int nx=i+dir[d], ny=j+dir[d+1];
                        if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]!=0){//確認延伸方向在範圍內，且是陸地
                            if(!hash.count(grid[nx][ny])){    //如果沒有重複計算的話
                                count+=islandSize[grid[nx][ny]];//就把它的面積加起來
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
        if(x<0 || y<0 || x>=n || y>=n || grid[x][y]!=1)    //確保他是在界內，且是還沒被探詢過的陸地
            return 0;
        int count=1;
        grid[x][y]=ID;        //把她填成目前的編號
        for(int i=0;i<4;i++)
            count+=dfs(grid,x+dir[i],y+dir[i+1], ID, n);    //延伸出去
        return count;
    }
};
