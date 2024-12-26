class Solution {    //BFS, Khan/s algorithm;
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if (n == 1) return 1;
        vector<vector<int>> adj(n);//連結圖
        vector<int> deg(n);//出入度
        //建立關係圖
        for(auto& i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            deg[i[0]]++;
            deg[i[1]]++;   
        }
      //只把葉子 push進q裡
        queue<int> q;
        for(int i=0;i<n;i++)
            if(deg[i]==1)
                q.push(i);
        int cnt=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
          
            deg[curr]--;
          //如果這個葉子(或以這個葉子為根節點的樹)可以自成component，cnt++
            if(values[curr]%k==0)
                cnt++;
          
          //理論上在這一步只會從葉子往上找到他的parent(只有一個)，但由於這是一個無向圖，所以要掃描完其所有的連接邊才會知道
            for(int i:adj[curr]){
                if(deg[i]==0)   continue;  //這個葉子(節點)已經被掃描完/切出去了，跳過
                
              //可以往下走的話，代表i 是其parent
                values[i]=(values[i]+values[curr])%k;  //把他的分枝的value加進他的parent裡，
                if(--deg[i]==1)  //然後就可以把它切出去了(parent的degree--)，然後如果切完他之後，parent也變成了葉子，那就把它加進queue裡 
                    q.push(i);
                break;
            }
        }
        return cnt;
    }
};
