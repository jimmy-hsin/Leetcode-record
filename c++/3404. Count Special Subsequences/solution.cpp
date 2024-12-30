class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        unordered_map<double, long long> hash;
        int n=nums.size();
        long long count=0;
        for(int r=4;r<n;r++){
            int q=r-2;
            for(int p=0 ; p < q-1 ; p++){
                double ratio=(double) nums[p]/nums[q];
                hash[ratio]++;
            }
            for(int s=r+2;s<n;s++){
                double ratio=(double) nums[s]/nums[r];
                count+=hash[ratio];
            }
        }
        return count;
    }
};
