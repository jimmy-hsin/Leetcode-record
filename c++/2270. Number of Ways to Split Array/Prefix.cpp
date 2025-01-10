class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=0;
        for(int& i:nums)
            sum+=i;
        
        int count=0;
        long long subSum=0;
        for(int i=0;i<nums.size()-1;i++){
            subSum+=nums[i];
            if(subSum*2 >= sum)
                count++; 
        }
        return count;
    }
};
