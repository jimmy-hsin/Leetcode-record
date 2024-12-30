class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size(), m=str2.size();
        int i=0,j=0;
        while(i<n && j<m){
            int c1=str1[i]-'a', c2=str2[j]-'a';    //取出兩者的字母的排序
            if(c1==c2 || (c1+1)%26==c2)            //如果str2[j]可以自str1[i]轉換
                i++, j++;                    //兩個都可以望下一步邁進
            else
                i++;                            //否則換str1的下一個字母試試
        }
        return j==m;  //看看str2的所有字母有沒有都湊到了
    }
};
