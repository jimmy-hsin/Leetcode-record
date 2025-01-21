class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        long long back = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long front = 0;
        
        long long minRes=LLONG_MAX; 
        for(int i=0;i<n;i++){
            back-=grid[0][i];
            long long maxVal=max(back, front);
            minRes=min(minRes, maxVal);
            front+=grid[1][i];     
        }
        return minRes;
    }
};
