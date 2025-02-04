class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res=0;
        int tempRes=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) //如果比前一個數小，就繼續往後加
                tempRes+=nums[i];
            else{                //不然就重開一條subarray,自己當開頭
                res=max(res,tempRes);    //紀錄最大的前一個subarray的和
                tempRes=nums[i];
            }   
        }
        res=max(res,tempRes);
        return res;
    }
};
