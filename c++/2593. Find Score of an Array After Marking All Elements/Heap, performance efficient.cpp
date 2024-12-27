class Solution {
public:
    long long findScore(vector<int>& nums) { 
        int n=nums.size();
        vector<pair<int,int>> pq;
        for(int i=0;i<n;i++)
            pq.push_back({nums[i],i});
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
