class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>> pos(n);//val, index;
        for(int i=0;i<n;i++)
            pos[i]={nums[i],i};
        ranges::sort(pos);
        
        vector<int> group;//紀錄每個數字該擺在哪裡
        int pre=0;  //每個組別的斷點
        group.push_back(pos[0].second);
        for(int i=1;i<n;i++){
            if(pos[i].first-pos[i-1].first>limit){
                sort(group.begin()+pre, group.end());//整理每個組別的位置(由前到後排序)
                pre=i;
            }
            group.push_back(pos[i].second);
        }

        sort(group.begin()+pre, group.end());

        for(int i=0;i<n;i++){
            nums[group[i]]=pos[i].first;
        }
        return nums;
    }
};
