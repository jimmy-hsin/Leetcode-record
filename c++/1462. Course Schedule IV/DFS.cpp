class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bitset<100>> pre(n); // 每個課程的先修課程集合
        for (auto& p : prerequisites) {
            pre[p[1]].set(p[0]); // 將 p[0] 設為 p[1] 的直接先修課程
        }

        vector<int> visited(n, 0); // 記錄是否已訪問
        for (int i = 0; i < n; ++i) {
            dfs(pre, i, visited); // 計算每個課程的所有先修課程
        }

        vector<bool> res;
        for (auto& q : queries) {
            res.push_back(pre[ q[1] ][ q[0] ]); // 判斷 q[0] 是否是 q[1] 的先修課程
        }
        return res;
    }

    void dfs(vector<bitset<100>>& pre, int node, vector<int>& visited) {
        if (visited[node]) return; // 如果已訪問，直接返回
        visited[node] = 1;         // 標記為已訪問
        for (int i = 0; i < pre.size(); ++i) {
            if (pre[node].test(i)) { // 如果 i 是 node 的直接先修課程
                dfs(pre, i, visited);  // 遞迴處理 i
                pre[node] |= pre[i];   // 將 i 的所有先修課程合併到 node
            }
        }
    }
};
