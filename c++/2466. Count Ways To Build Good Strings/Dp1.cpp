class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int mod=1e9+7;
        vector<int> dp(high+1,0);
        dp[0]=1;
        for(int i=0;i<high;i++){
            if(i+zero<=high)
                dp[i+zero]=(dp[i+zero]+dp[i])%mod;
            if(i+one<=high)
                dp[i+one]=(dp[i+one]+dp[i])%mod;
        }
        long long res=0;
        for(int i=low;i<=high;i++)
            res+=dp[i];
        return res%mod;
    }
};
