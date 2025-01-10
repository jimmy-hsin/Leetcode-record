class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
      //先統計字串裡面有多少個'1'
        int ones=0;
        for(char& c:s){
            ones+=c-'0';
        }

        int zeros=0, res=0;
        for(int i=0;i<n-1;i++){  //因為是只能計算左邊的'0'，所以少掃描最後一個
            if(s[i]=='0')//如果這個是'0' 那zeros就把他統計起來
                zeros++;
            else        //如果這個是'1'，代表這個1要換到左邊去了，把total的ones減去他之後就代表右邊的'1'的數量
                ones--;
            res=max(res, zeros+ones);
        }
        return res;
    }
};
