class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        /*
          題意表示，現在這個街道有n個房子，n為一個偶數，用來粉刷房子的顏色總共有三種，每棟房子粉刷不同顏色會有不同的花費(不同的花費可在cost陣列中查詢)，
            現在有兩項粉刷規則要遵守，請計算符合規則的情況下的最低花費為何
            1. 相鄰的房子不能使用同個顏色
            2. 離中心點距離相同的房子顏色也不能一樣
        */
          /*
            解法，將互相對稱的房子的組合綁定在一起，我們可以得出6種合規的組合(頭的顏色，尾的顏色)(12, 13, 21, 23, 31, 32) 
            要使用每種組合，前面一組合規的組合如下:
            假設我們當前的房子pair 使用的組合為12，那麼前面一個pair在合規的情況下可以有以下幾種組合: 21、23、31
            其他結果以此類推
          */
        int mid=n/2;
        
        vector<long long> dp(6,0), temp(6,0);
        dp[0]=cost[0][0]+cost[n-1][1];   //12
        dp[1]=cost[0][0]+cost[n-1][2];   //13
        dp[2]=cost[0][1]+cost[n-1][0];   //21
        dp[3]=cost[0][1]+cost[n-1][2];   //23
        dp[4]=cost[0][2]+cost[n-1][0];   //31
        dp[5]=cost[0][2]+cost[n-1][1];   //32
      
        for(int i=1;i<mid;i++){
            temp[0]=min({dp[2],dp[3],dp[4]}) +cost[i][0]+cost[n-1-i][1];    // 12 +  min of(21,23,31)
            temp[1]=min({dp[4],dp[5],dp[2]}) +cost[i][0]+cost[n-1-i][2];    // 13 +  min of(31,32,21)
            temp[2]=min({dp[0],dp[1],dp[5]}) +cost[i][1]+cost[n-1-i][0];    // 21 +  min of(12,13,32)
            temp[3]=min({dp[5],dp[4],dp[0]}) +cost[i][1]+cost[n-1-i][2];    // 23 +  min of(32,31,12)
            temp[4]=min({dp[1],dp[0],dp[3]}) +cost[i][2]+cost[n-1-i][0];    // 31 +  min of(13,12,23)
            temp[5]=min({dp[3],dp[2],dp[1]}) +cost[i][2]+cost[n-1-i][1];    // 32 +  min of(23,21,13)
            dp=temp;
        }
        
        return *min_element(dp.begin(), dp.end());
        
    }
};
