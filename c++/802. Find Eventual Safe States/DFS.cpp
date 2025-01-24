class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);//0: unvisited, 1:processing(probably unsafe), 2:safe
        vector<int> res;
        for(int i=0;i<n;i++)
            if(safe(i, graph, visited))
                res.push_back(i);
    
        return res;
    }
    bool safe(int node, vector<vector<int>>& graph, vector<int>& visited){
        if(visited[node]!=0)  //有兩個可能他會進到這裡來: 1. 已經完成最終標記(也就是dfs的最後兩行，把狀態設為2)，知道這個節點已經是safe了;   
            return visited[node]==2;                  //2. 他還在下面的for迴圈的處理中，還沒到最終標記步驟就回來了，那就代表這個節點在循環內

        visited[node]=1; //先把它標記成處理中
        for(auto& nxNode:graph[node]){
            if(!safe(nxNode,graph, visited))  //看看他的下游是不是全部都是safe
                return false;
        }
        visited[node]=2;  //如果下游都是safe，那就把他的狀態改為safe
        return true;
    }
};
