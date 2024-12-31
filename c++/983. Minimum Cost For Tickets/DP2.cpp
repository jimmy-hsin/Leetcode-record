class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.back();
        vector<int> dp(n+1,0);
        int x=0;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            if(i==days[x]){ //如果這天有要搭車
                dp[i]+=costs[0];    //那就先預設要買單日票
                if(days[x]!=n)      //避免x超出範圍造成RTE
                    x++;
            }

            if(i>=30)
                dp[i]=min({dp[i], dp[i-7]+costs[1], dp[i-30]+costs[2]});   
            else if (i>=7)
                dp[i]=min({dp[i], dp[i-7]+costs[1], costs[2]});
            else
                dp[i]=min({dp[i], costs[1], costs[2]});      
        }

        return dp[n];
    }
};
