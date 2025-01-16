class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res=0;
        if(nums2.size()%2){
            for(int i:nums1)
                res^=i;
        }
        if(nums1.size()%2){
            for(int i:nums2)
                res^=i;
        }
        return res;
    }
};
