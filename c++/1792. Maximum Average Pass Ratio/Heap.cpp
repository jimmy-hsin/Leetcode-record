class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<pair<double, pair<int, int>>> pq; //增幅，通過人數，整班人數
        for(auto& c:classes)
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});//
      //塞入學霸
        while(extraStudents>0){
            auto [currGain,pair]=pq.top();   //取出增幅成長最好的班級
            auto [pass,total]=pair;
            pq.pop();
            
            extraStudents--;
            pq.push({gain(pass+1,total+1),{pass+1,total+1}});
        }
      //統計結果
        double x=0.0;
        while(!pq.empty()){
            auto [gain, pair]=pq.top();
            auto [pass, total] = pair;
            pq.pop();
            x+=(double)pass / total;
        }
        return x/n;
    }
//計算多加一個學霸(絕對通過者) 對於整體通過率的增幅有多大
    double gain(int pass, int total){
        double before=(double) pass/total;
        double after=(double) (pass+1)/(total+1);
        return after-before;
    }
};
