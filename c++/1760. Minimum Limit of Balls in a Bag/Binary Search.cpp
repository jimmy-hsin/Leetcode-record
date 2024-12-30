class Solution {
public:
    int minimumSize(vector<int>& nums, int k) {
        int low=1;
        int high=*max_element(nums.begin(), nums.end());  //max_element 傳遞的是數值最大元素的指標，用'*' 來進行dereference
        while(low<high){ 
            int mid=low+(high-low)/2; 
            int tempSplit=0;
          //統計每個元素所需消耗的分割數
            for(int& i:nums)
                tempSplit+=(i-1)/mid;  //如果剛好等於mid就不用分割(所以i-1)
            if(tempSplit>k) //分太小包了，操作次數不夠用
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
};
