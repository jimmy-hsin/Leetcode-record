class Solution {
public:
    vector<int> visited;
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1, m=edges2.size()+1;
        vector<vector<int>> adj1(n), adj2(m);
        for(auto& i:edges1){
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }

        for(auto& i:edges2){
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
      
        int maxNode=0;
        vector<bool> visited;
      
        visited = vector<bool>(n,0);
        int maxDepth1=0; maxNode=0;         //maxDepth紀錄以0為起點的最大深度 
        dfs(0, 0, visited, adj1, maxDepth1,maxNode); //maxNode會紀錄第一次搜索的最深節點
        visited = vector<bool>(n,0);         //重設visited，因為我們要再搜索一次
        dfs(maxNode,0, visited, adj1, maxDepth1, maxNode);   //以maxNode為起點重新搜索一遍，就可以找到在graph1中的最長節點間距離

        //對graph2做一樣的事
        visited =vector<bool>(m,0);
        int maxDepth2=0; maxNode=0;   
        dfs(0, 0, visited, adj2, maxDepth2,maxNode);
        visited=vector<bool> (m,0);         
        dfs(maxNode,0, visited, adj2, maxDepth2, maxNode);

        int centerDepth= (maxDepth1+1)/2 +   (maxDepth2+1)/2 +1;   //把兩個圖的中心點連接後的深度
        return max({centerDepth, maxDepth1, maxDepth2});
    }

    void dfs(int node, int depth, vector<bool>& visited, vector<vector<int>>& adj, int& maxDepth, int& maxNode){
        visited[node] = 1;
        if(depth>maxDepth){
            maxNode=node;
            maxDepth=depth;
        }
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, depth + 1, visited, adj, maxDepth, maxNode);
            }
        }
        return;
    }
};
