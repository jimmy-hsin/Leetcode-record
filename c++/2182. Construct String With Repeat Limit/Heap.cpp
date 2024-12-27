class Solution {
public:
    string repeatLimitedString(string s, int k) {
      //統計所有字母的個數
        vector<int> cnt(26,0);
        for(char c:s)
            cnt[c-'a']++;
      //把有出線的字母及其個數塞進最大堆裡(堆頂為最大值: z)
        priority_queue<pair<char,int>> pq;
        for(int i=0;i<26;i++){
            if(cnt[i])
                pq.push({'a'+i,cnt[i]});
        }

        string res="";
        while(!pq.empty()){
            auto [c1,cnt1]=pq.top();
            pq.pop();
            int len=min(cnt1,k);  //連續的元素不得超過k個
            //for(int i=0;i<len;i++)  res+=c1;
            string sub1(len,c1);  //創建一個小字串，長度為len，元素都是c1所代表的字母
            res+=sub1;

            if(cnt1-len){  //如果塞完小字串之後，c1還有剩，那就必須要插一個c2來中斷這個連續的字母串
                if(pq.empty())  //如果沒有東西可以拿來當間隔，代表res最長就這樣了，直接回傳
                    return res;
              //否則就借一個c2來當間隔
                auto [c2,cnt2]=pq.top();  
                pq.pop();
                res+=c2;
                if(cnt2>1)  //c2借完一個還有剩，重新塞回去
                    pq.push({c2,cnt2-1});
                
                pq.push({c1,cnt1-len});//把剩下的c1也重新塞回去
            }
        }
        return res;
        
    }
};
