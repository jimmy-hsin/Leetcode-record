class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> det(n,0);
        for(int i=1;i<n;i++){
            if(nums[i]%2==nums[i-1]%2)  //如果nums[i]跟他前一個元素的奇偶校正一樣，代表這邊不special，出現error
                det[i]=1;
        }
        for(int i=1;i<n;i++)  //統計index i 之前出現幾個error
            det[i]+=det[i-1];
      
        vector<bool> res;
        for(auto& i:queries){
          //看看queries指定的區間裡面有沒有error，若沒有的話val就為0，這個querie的結果為true
            int val=det[i[1]]-det[i[0]];
            res.push_back(val==0);
        }
        return res;
    }
};
