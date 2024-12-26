class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
      //建立連接圖
        vector<vector<int>> adj(n);
        for(auto& i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int cnt=0;    //統計合規的component數量
        dfs(0,-1,adj,values, k, cnt);//從節點0出發，由於其沒有父節點，所以將其parent設為一個不在界點數值範圍內的值(-1)
        return cnt;
    }
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& values, int k, int& cnt){
        int sum=0;
      //由於圖表示DAG，因此parent的值必須是其所有的子節點的value總和，再加上自己的value，而子節點不能算到父節點
        for(int child: adj[node]){ 
            if(child != parent){ //掃描除了node自己的parent外的其他連接點
                sum+=dfs(child, node, adj,values,k,cnt);
                sum%=k;
            }
        }
        sum+=values[node];
      //如果以node作為根節點(不含其parent) 的整棵樹的value總和能被k整除，代表整棵樹可以被拆出來成獨立的component
        if(sum%k==0)    cnt++;
        return sum;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
