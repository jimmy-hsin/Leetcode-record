class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=accumulate(nums.begin(), nums.end(), 0);
        int diff=(total-target);  //total 跟target之間的差距，代表要減去的數值量
      
      //因為整體的數值要嘛是+nums[i], 要嘛是-nums[i]，兩個選擇之間的差距2*nums[i]
        if(diff%2)  return 0;   //所以如果diff算出來是奇數，那代表無法用nums湊出target值
        diff/=2;                //不然的話，就把diff/2， 作為所有被選為要做減法操作的元素和  
        int cnt=0;     //cnt 統計所有可行的組合數量
        backtracking(nums,diff,0,cnt);
        return cnt;
    }
    void backtracking(vector<int>& nums,int diff, int currIdx, int& cnt){
        if(diff==0) cnt++;  //如果此解法可行，那就納入組合數當中
        if(diff<0)  return;  //代表這個選法已經超出diff預計的數量了，後面的元素也無法在納入選擇中了，所以進行剪枝(pruning)
        for(int i=currIdx;i<nums.size();i++){  //否則，假設diff把元素i納入減法操作的集合中，再繼續往下做搭配   
            backtracking(nums,diff-nums[i],i+1,cnt); 
        }
    }
};
