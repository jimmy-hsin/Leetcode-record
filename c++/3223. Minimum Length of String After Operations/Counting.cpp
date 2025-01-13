class Solution {
public:
    int minimumLength(string s) {
        //這個遊戲很簡單，就是判斷一個字母的數量是否大於等於3
        //如果是的話，在同個字母形成的subarray中，從頭、尾各去掉一個元素，直到該字母的個數小於3為止
        
        //統計字母個數
        vector<int> count(26,0);
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
        }
        
        int sum=0;
        for(int& i:count){
            if(i==0)    continue;
            //因為我們每次操作都會少兩個元素，所以若是字母個數為奇數，那最後只會剩下一個
            if(i%2)
                sum++;
            //若字母個數為偶數，則會剩下兩個
            else
                sum+=2;
        } 
        return sum;
    }
};
