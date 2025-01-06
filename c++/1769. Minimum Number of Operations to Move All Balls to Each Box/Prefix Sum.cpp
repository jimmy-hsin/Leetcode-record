class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        if(n==1)    return {0};
        vector<int> cnt(n,0);
        vector<int> prefix(n,0); //統計離原點的總操作長度
        if(boxes[0]=='1')
            cnt[0]=1;
        for(int i=1;i<n;i++){
            cnt[i]=cnt[i-1];
            prefix[i]=prefix[i-1];
            if(boxes[i]=='1'){
                cnt[i]++;
                prefix[i] += i;
            }
        }
        
        vector<int> res(n,0);
        res[0]=prefix.back();
        for(int i=1;i<n-1;i++){ //去頭去尾，因為邊界操作比較特殊
            //front
            int cnt1=cnt[i-1];  //在i前面有多少個'1'
            res[i] += cnt1*i - prefix[i-1];  //把有'1'的地方到高度i 之間的空格補起來，所需的方塊數
            //behind
            int cnt2=cnt.back()-cnt[i];  //在i後面有多少個'1'
            res[i]+=prefix.back()-prefix[i]-cnt2*i;
        }
        res[n-1]=cnt[n-2]*(n-1)-prefix[n-2]; //相當於上面for loop 的front, 把i=n-1帶入

        return res;
    }
};
