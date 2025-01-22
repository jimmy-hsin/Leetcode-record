class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        /*
            邏輯很簡單，就是基本的BFS，初始對列為先找到有水的地方
            以這些點為圓心，一層一層的擴散(長高)出去，
            我們先把所有人的初始值設為-1，這樣方便我們觀察那些點有被照訪過
            如果某些點已經被擴散過的話，他就不會再長高
        */
        int m=isWater.size(), n=isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n,-1));
        vector<int> dirc={-1,0,1,0,-1};
        //先將有水的位置加進對列，並把他們的高度設為0
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(isWater[i][j]){
                    q.push({i,j});
                    res[i][j]=0;
                }
                    
        int level=1;
        while(!q.empty()){
            int k=q.size();    //先確認這一層(高度)有幾個點
            for(int i=0;i<k;i++){
                auto [x,y]=q.front();    //取出對列的頭
                q.pop();

                for(int i=0;i<4;i++){    //往四個方向擴張
                    int nx=x+dirc[i], ny=y+dirc[i+1];    
                    if(nx>=0 && ny>=0 && nx<m && ny<n && res[nx][ny]==-1){    //確認擴張的方向還在範圍內，且沒被照訪過
                        q.push({nx,ny});    //就可以把擴張方向加進對列
                        res[nx][ny]=level;  //並把擴張方向的高度設為比自己高一格  
                    }     
                }
            }
            level++; //每掃描完一層就會長高一點
        }
        return res;
        
    }
};
