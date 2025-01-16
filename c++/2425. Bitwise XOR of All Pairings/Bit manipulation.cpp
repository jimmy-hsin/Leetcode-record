class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        /*
            這題邏輯其實很簡單，XOR有一個特性，對同樣的數做XOR會得到0，
            所以如果nums1裡的數要能對結果產生影響，nums2的總長度必須是奇數個，
            否則nums1裡的元素產生的配對總數為偶數個的情況下，所XOR的結果都會為0，就不會對結果有影響

            nums2同理，...略...
        */
        int res=0;
        if(nums2.size()%2){
            for(int i:nums1)
                res^=i;
        }
        if(nums1.size()%2){
            for(int i:nums2)
                res^=i;
        }
        return res;
    }
};
