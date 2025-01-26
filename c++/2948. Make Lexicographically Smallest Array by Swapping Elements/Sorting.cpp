class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        /*  解題方法很簡單，先把所有的數做排序，然後進行分組，
            分組的方式就是，如果排序後的兩個相鄰的數的差距大於limit，那我們就會把它分配在不同的組別內，他們兩個之間就是分組的斷點
            我們同時也紀錄了每個數字的原始位置，組別內的位置都可以隨意替換，
            所以我們第二步要做的就是把組別內的位置index由前到後進行排列後，這樣就會是每個數字的最終位置
        */
        int n=nums.size();
        //紀錄每個數字的原始位置
        vector<pair<int,int>> sorted(n);//val, index;
        for(int i=0;i<n;i++)
            sorted[i]={nums[i],i};
        //然後對數字進行排序
        ranges::sort(sorted);
        
        vector<int> index;//紀錄每個數字最終該擺在哪裡
        int pre=0;  //每個組別的斷點
        index.push_back(sorted[0].second);
        for(int i=1;i<n;i++){
            if(sorted[i].first-sorted[i-1].first > limit){    //遇到斷點了
                sort(index.begin()+pre, index.end());//整理前一個組別的index(由前到後排序)
                pre=i;    //重設斷點
            }
            index.push_back(sorted[i].second); 
        }

        sort(index.begin()+pre, index.end());//整理最後一組的index

        for(int i=0;i<n;i++)
            nums[index[i]]=sorted[i].first; 
        return nums;
    }
};
