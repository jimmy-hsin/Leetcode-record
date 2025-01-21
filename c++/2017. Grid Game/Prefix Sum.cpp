class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        //先產出兩條陣列的prefix表
        vector<long long> prefix1(n+1,0);
        vector<long long> prefix2(n+1,0);
        for(int i=0;i<n;i++){
            prefix1[i+1]=prefix1[i]+grid[0][i];
            prefix2[i+1]=prefix2[i]+grid[1][i];
        }
         
        long long minRes=LLONG_MAX; 
        for(int i=0;i<n;i++){
            //計算每個轉折處的結果
            long long back=prefix1.back() - prefix1[i+1];    //第一排轉折處後面的sum
            long long front=prefix2[i];                      //第二排轉折處前面的sum
            long long maxVal=max(back,front);                //計算這兩者的最大值
            minRes=min(minRes, maxVal);                      //記錄所有可能性中的最小值
        }
        return minRes;
    }
};
