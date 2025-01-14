/*
 *  Author      : Reese
 *  Created On  : 2024-12-21 10:57
 *  Description : https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/
 */

// 將 adj 鄰接圖表創建為全域變數，這樣可以提高效能和降低記憶體使用率
// 如果是在 class 內創建，每次呼叫 maxKDivisibleComponents() 都得重新分配和釋放記憶體
const int N = 3e4 + 5;
std::vector<std::vector<int>> adj(N);

class Solution {
  public:
    int res = 0;
    int maxKDivisibleComponents(int n, std::vector<std::vector<int>> &edges, std::vector<int> &values, int k) {
        // 清空 adj 鄰接圖表，避免之前的測試資料影響當前測試資料的結果
        for (auto &a : adj) {
            a.clear();
        }
        // 創建鄰接圖表
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(-1, 0, values, k);

        return res;
    }

    long long dfs(int currNode, int parent,  const std::vector<int> &values, const int &k) {
        long long sum = values[currNode];
        for (auto &nextNode : adj[currNode]) {
            if (nextNode != parent) {
                sum += dfs(nextNode, currNode, values, k);
            }
        }

        // 如果當前子樹總和能被 k 整除，則該子樹能和 parent node 分開形成獨立的 component
        sum %= k;
        res += (sum == 0);
        return sum;
    }


};
