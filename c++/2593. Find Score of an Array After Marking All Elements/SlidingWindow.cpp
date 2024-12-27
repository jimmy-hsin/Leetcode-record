class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int r = 0; r < n; r++) {
            int windowL= r;  //先記住現在的位置，當作區間起點
            while (r + 1 < n && nums[r + 1] < nums[r])  //如果後面的那個數字比現在的還小，r指標向後移一格
                r++;
          //處理上次掃描到的邊界，跟這次取到的區間
            for (int j = r; j >= windowL; j -= 2) { //j-=2，因為要跳著數 
                ans += nums[j];
            }
            r++;    // 因為nums[r]已經被我們數進來了，所以要跳過他的鄰居
        }
        return ans;
    }
};
