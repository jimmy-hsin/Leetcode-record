class Solution {
public:
    bool canConstruct(string s, int k) {
        //因為總共要湊到k個回文，如果s的字數不夠，當然就湊不成
        if(s.size()<k)  return false;
        //先統計所有的字母的個數
        vector<int> count(26,0);
        for(char c:s){
            count[c-'a']++;
        }
        //因為一個回文只能有一個中間字，其他的都是必須要成對的，
        //所以我們看看有幾個字母的字數是奇數的，就代表至少需要有幾個回文才能合理地把所有字母用完
        int odd=0;
        for(int i:count){
            odd+=(i%2);
        }
        //如果奇數字母的個數大於k，那就代表無法用完，回傳false
        return odd<=k;
    }
};
