class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        string compact1, compact2;//去掉空格後的字串
        vector<int> L1, R1;//紀錄start中'L'、'R'的位置
        vector<int> L2, R2;//紀錄target中'L'、'R'的位置
        for(int i=0;i<n;i++){
            if(start[i]=='R' || start[i]=='L'){
                compact1+=start[i];
                if(start[i]=='L')
                    L1.push_back(i);
                else
                    R1.push_back(i);
            }
            if(target[i]=='R' || target[i]=='L'){
                compact2+=target[i];
                if(target[i]=='L')
                    L2.push_back(i);
                else
                    R2.push_back(i);
            }
        }
        if(compact1!=compact2)  //壓縮後的字母順不同，代表交換過程中，'R'、'L'會互相衝撞到
            return false;
        for(int i=0;i<L1.size();i++)    //如果有target的第i個L，比start的第i個L還右邊，會因為start的第i個L無法往右邊移動而出錯
            if(L1[i]<L2[i])
                return false;
        for(int i=0;i<R1.size();i++)    //R同理
            if(R1[i]>R2[i])
                return false;
        return true;
    }
};
