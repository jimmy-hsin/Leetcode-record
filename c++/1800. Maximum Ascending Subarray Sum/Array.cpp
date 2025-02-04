class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res=0;
        int tempRes=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])
                tempRes+=nums[i];
            else{
                res=max(res,tempRes);
                tempRes=nums[i];
            }   
        }
        res=max(res,tempRes);
        return res;
    }
};
