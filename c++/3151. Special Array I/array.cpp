class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        //邏輯太簡單，就不解釋了
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]%2 == nums[i]%2)
                return false;
        }
        return true;
    }
};
