class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> prefix(n+1,0);  //紀錄shifting 的方法類似爬山一樣，只在高度有變化的地方紀錄
        for(auto& i:shifts){
            int start=i[0];
            int end=i[1];
            if(i[2]==0){  //如果shifting是逆著的
                prefix[start]--;  //start的地方高度下降一格
                prefix[end+1]++;  //end後面那一格的高度要升回來
            }
            else{    //shifting為正時，同理
                prefix[start]++;
                prefix[end+1]--;
            }
        }
      //把shift的高度變化表，整理成高度表
        for(int i=1;i<=n;i++){
            prefix[i]+=prefix[i-1];
        }
      
        for(int i=0;i<n;i++){
            int temp=(prefix[i])%26+26;  //因為每shift，26一個循環所以%26，+26的部分為可以把富庶的部分轉成正數
            s[i]=(temp+s[i]-'a')%26+'a';  //計算shift完之後會是什麼字母
        }
        return s;
    }
};
