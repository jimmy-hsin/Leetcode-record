class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        // 檢查target是否超過可達總和範圍
        if (target > total || target < -total) return 0;
        int diff = (total - target) / 2;
        if ((total - target) % 2 != 0) return 0; // 無法整除，無解
        
        // 使用動態規劃來計算子集和
        vector<int> dp(diff + 1, 0);
        dp[0] = 1; // sum為0時，只有1種方法：不選任何數字
        
        for (int num : nums) {
            for (int j = diff; j >= num; j--) { // 遞減防止重複使用同一元素
                dp[j] += dp[j - num];
            }
        }
        
        return dp[diff];
    }
};
