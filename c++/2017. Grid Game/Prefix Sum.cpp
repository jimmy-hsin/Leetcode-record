class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<long long> prefix1(n+1,0);
        vector<long long> prefix2(n+1,0);
        for(int i=0;i<n;i++){
            prefix1[i+1]=prefix1[i]+grid[0][i];
            prefix2[i+1]=prefix2[i]+grid[1][i];
        }

        long long minRes=LLONG_MAX; 
        for(int i=0;i<n;i++){
            long long back=prefix1.back() - prefix1[i+1];
            long long front=prefix2[i];
            long long maxVal=max(back,front);
            minRes=min(minRes, maxVal);
        }
        return minRes;
    }
};
