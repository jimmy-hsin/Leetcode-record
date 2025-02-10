class Solution {
public:
    /*
        題目已表明所有數字都是唯一的，因此我們先整理所有的積(O(n^2))，最多會有5E5次運算，再對他們的積做排序，
        統整同樣的積有幾個(K)，那麼總選擇數為C-k取2  *2(順序反轉)*2(順序反轉)=k*(k-1)*4
    */
    int tupleSameProduct(vector<int>& nums) {
        vector<int> product;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++)
                product.push_back(nums[i]*nums[j]);
        }
        ranges::sort(product);
        int count=0, same=1;
        product.push_back(0);//作為dummy，以便更好的處理最後一個元素
        for(int i=1;i<product.size();i++){
            if(product[i]==product[i-1])    same++;
            else{
                if(same>1) count+=same*(same-1)*4;
                same=1;
            }
        }
        return count;
        
    }
};
