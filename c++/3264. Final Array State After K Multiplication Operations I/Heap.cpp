class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
      //把nums裡面的數值和其index塞進pq裡
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int, int>> > pq; // val, index
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
      //重複以下步驟k次
        while(k--){
          //把最小中最前面的元素取出來
            auto [num,index]=pq.top(); // val, index
            pq.pop();
          //把他乘以multiplier
            nums[index]*=multiplier;
          //把改變後的元素重新推回pq裡
            pq.push({nums[index],index});
        }
        return nums;
    }
};
