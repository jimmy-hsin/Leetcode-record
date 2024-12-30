class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> mp(n+1,1);
        for(int& i:banned){
            if(i<=n)
                mp[i]=0;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(mp[i]==1){
                if(maxSum-i>=0){
                    maxSum-=i;
                    cnt++;
                }
                else
                    break;
            }
        }
        return cnt;
    }
};
