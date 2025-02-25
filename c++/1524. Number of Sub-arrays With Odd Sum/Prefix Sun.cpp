class Solution {
public:
    int MOD=1E9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
      //我們先計算，前i個元素的總和是奇數還是偶數(奇數為1，偶數為0)，並把結果存在prefix裡
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;i++)
            prefix[i+1]=(prefix[i]+arr[i])%2;
      //然後我們計算有幾個前綴是1的位置，而subarray的意思是一串連續的元素，
        long long odds=accumulate(prefix.begin(), prefix.end(), 0);
        long long evens=n+1-odds;
      //因此我們找出所有1的位置，他跟任何0之間所夾的元素和必為奇數，因此所有組合為0的個數*1的個數，由於數值過大要對MOD取模
        long long res=(odds*evens)%MOD;
        return (int) res;
      
      //ex: arr[]=  {1,2,3,4,5,6,7}
      //-->prefix={0,1,1,0,0,1,1,0}   (會多一個元素是因為subarray從i~j的取法是prefix[j]-prefix[i-1], 我們要在最前面多設一個元素，才能代表元素0也被納入subarray的狀況
      //--> odds=4, evens=7+1-4=4
      //--> res=odd*evens=16###
    }
};
