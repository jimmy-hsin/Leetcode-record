class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int breakpoint=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i])
                breakpoint++;
        }
        if(breakpoint==0)
            return true;
        if(breakpoint==1)
            return nums.back()<=nums[0];
        return false;
    }
};
