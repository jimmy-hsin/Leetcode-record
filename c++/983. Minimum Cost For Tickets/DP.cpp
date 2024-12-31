class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.back();  //整個旅程的最大天數
        vector<int> dp(n+1,0);  //設置DP表
        int x=0;  //設置在days中掃描的指標
      
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];    //統計旅行到這天的最低總花費
            if(i==days[x]){   //如果這天有要搭車
                dp[i]+=costs[0];    //那就先預設要買單日票
                if(days[x]!=n)      //避免x超出範圍造成RTE
                    x++;
            }
            //判斷跟前面一起買會不會比較便宜
            if(i>7)  //包含自己的前七天一起買  (如果這七天都沒有要搭車，因為都沒有買單日票造成總花費上升，那麼總花費理論上就會跟七天前一樣，在這步裡 dp[i]==dp[i-7] < dp[i-7]+costs[1]
                dp[i]=min(dp[i], dp[i-7]+costs[1]);  //前八天 + 七日票的價格
            else  //因為某些機掰狀況，7日票賣的比單日票便宜
                dp[i]=min(dp[i], costs[1]);
          
            //同理
            if(i>30)
                dp[i]=min(dp[i],dp[i-30]+costs[2]);   
            else
                dp[i]=min(dp[i], costs[2]);         
        }

        return dp[n];
    }
};
