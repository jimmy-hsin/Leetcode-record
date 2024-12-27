class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,r=0;
        k=2*k;
        int res=0;
        while(r<n){
            while(r<n && (nums[r]-nums[l])<=k)
                r++;
            res=max(res,r-l);
            l++;
        }
        return res;
    }
};
