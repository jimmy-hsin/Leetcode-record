class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,r=0;
        k*=2;//由於可以移動的範圍是nums[i]-k ~ nums[i]+k，整個區間的大小為2k
        int res=0;
        while(r<n){
            while(r<n && (nums[r]-nums[l])<=k)    //如果nums[r]相對於nums[l]還在範圍內，則可以擴張右區間的邊界
                r++;
            res=max(res,r-l);    //超過的話，先統計一下目前的合規區間長度
            l++;
        }
        return res;
    }
};
