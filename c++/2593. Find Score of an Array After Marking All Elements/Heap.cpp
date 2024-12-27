class Solution {
public:
    long long findScore(vector<int>& nums) {
      //把(數值,index)塞進pq裡
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n=nums.size();
        for(int i=0;i<n;i++)
            pq.push({nums[i],i});

        vector<bool> visited(n,0);
        long long sum=0;
        while(!pq.empty()){
            auto [curr, index]=pq.top();
            pq.pop();
            if(!visited[index]){
                sum+=curr;
              //更新visited表
                visited[index]=1;
                if(index!=0)//mark左邊
                    visited[index-1]=1;
                if(index!=n-1)//mark右邊
                    visited[index+1]=1;
            }
        }
        return sum;
    }
};
