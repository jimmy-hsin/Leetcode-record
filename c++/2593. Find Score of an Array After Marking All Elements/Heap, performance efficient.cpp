class Solution {
public:
    long long findScore(vector<int>& nums) { 
        int n=nums.size();
        //由於heap裡的元素我們只要使用一次就丟了，沒有要重新push回去，因此使用vector作為容器再對她做排序的計算量會比較小
        vector<pair<int,int>> pq(n);
        for(int i=0;i<n;i++)
            pq[i]={nums[i],i};
        sort(pq.begin(),pq.end());
        
        vector<bool> visited(n,0);
        long long sum=0;
        for(int i=0;i<n;i++){
            auto [curr, index]=pq[i];
            if(!visited[index]){
                sum+=curr;
                visited[index]=1;
                if(index!=0)
                    visited[index-1]=1;
                if(index!=n-1)
                    visited[index+1]=1;
            }
        }
        return sum;
    }
};
