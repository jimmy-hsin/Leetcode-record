class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        /*  解題方法很簡單，先把所有的數做排序，然後進行分組，
            分組的方式就是，如果兩排序後的兩個相鄰的數的差距大於limit，那他們倆個就會是分組的斷點位置
            我們同時也紀錄了每個數字的原始位置，組別內的位置都可以隨意替換，
            所以我們第二步要做的就是把組別內的index由前到後進行排列後，這樣就會是每個數字的最終位置
        */
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

        for(int i=0;i<n;i++)
            nums[group[i]]=pos[i].first;
        return nums;
    }
};
