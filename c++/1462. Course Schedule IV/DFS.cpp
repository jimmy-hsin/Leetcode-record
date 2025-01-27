class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        /*
            題目描述: 現在共有n個課程，其中在prerequisites中我們紀錄了prerequisites[i][1]的直接先修課程:prerequisites[i][0];
            現在我們有一個詢問陣列，請回傳queries[i][0]是不是queries[i][0]的先修課程
            注意: 若c的先修課程為b，b的先修課程為a，則a為c的間接先修課程，仍然為先修課程關係
        */
        
        //由於我們接下來要做的dfs的特性，且課程數上限僅為100，所以使用bitset來做最合適
        vector<bitset<100>> pre(n); // 每個課程的先修課程集合，pre[i]的哪個位置被set了，就代表哪個位置是i的先修
        for (auto& p : prerequisites) 
            pre[p[1]].set(p[0]); // 將 p[0] 設為 p[1] 的直接先修課程
        
        vector<int> visited(n, 0); // 記錄是否已訪問
        for (int i = 0; i < n; ++i) 
            dfs(pre, i, visited); // 計算每個課程的所有先修課程
        
        vector<bool> res;
        for (auto& q : queries) 
            res.push_back(pre[ q[1] ][ q[0] ]); // 判斷 q[0] 是否是 q[1] 的先修課程，也就是去看q[1]的第q[0]個位元有沒有set   
        return res;
    }

    void dfs(vector<bitset<100>>& pre, int node, vector<int>& visited) {
        if (visited[node]) return; // 如果已訪問，直接返回
        visited[node] = 1;         // 標記為已訪問
        for (int i = 0; i < pre.size(); ++i) {
            if (pre[node][i]) {         // 如果 i 是 node 的直接先修課程
                dfs(pre, i, visited);   // 那就往下搜尋
                                        // 在i也將它所有的先修課程搜尋完了之後
                pre[node] |= pre[i];    //將 i 的所有先修課程合併到 node (兩個bitset做OR操作)
            }
        }
    }
};
