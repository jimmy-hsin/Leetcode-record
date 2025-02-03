class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int deM=1,inM=1;
        int de=1, in=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                in++;
                de=1;
            }
            else if(nums[i]<nums[i-1]){
                de++;
                in=1;
            }
            else
                de=in=1;   
            deM=max(deM,de);
            inM=max(inM,in);
        }
        return max(inM,deM);
    }
};
