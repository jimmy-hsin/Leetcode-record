class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(), n=isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n,-1));
        vector<int> dirc={-1,0,1,0,-1};
        
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(isWater[i][j]){
                    q.push({i,j});
                    res[i][j]=0;
                }
                    
        int level=1;
        while(!q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                auto [x,y]=q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int nx=x+dirc[i], ny=y+dirc[i+1];
                    if(nx>=0 && ny>=0 && nx<m && ny<n && res[nx][ny]==-1){
                        q.push({nx,ny});
                        res[nx][ny]=level;
                    }     
                }
            }
            level++;
        }
        return res;
        
    }
};
