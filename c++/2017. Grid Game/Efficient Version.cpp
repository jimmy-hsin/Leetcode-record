class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        long long top_sum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long bottom_sum = 0;
        long long minRes=LLONG_MAX; 
        for(int i=0;i<n;i++){
            top_sum-=grid[0][i];
            long long maxVal=max(top_sum, bottom_sum);
            bottom_sum+=grid[1][i];
            minRes=min(minRes, maxVal);
        }
        return minRes;
    }
};
