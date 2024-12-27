class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> bad(n,0);
        for(int i=1;i<n;i++){
            bad[i]=bad[i-1];
            if((nums[i]%2)== (nums[i-1]%2))
                bad[i]++;
        }
        vector<bool> res;
        for(auto& i:queries){
            int x=bad[i[1]]-bad[i[0]];
            res.push_back(x==0);
        }
        return res;
    }
};
