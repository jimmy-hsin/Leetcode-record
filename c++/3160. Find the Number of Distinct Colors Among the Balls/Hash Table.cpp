class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
	    //創建兩個哈希表, 一個紀錄當前球的顏色，一個統計個別顏色有多少顆球
	    unordered_map<int,int> balls;//balls,color
        unordered_map<int,int> hash;// color, counts
        int color_nums=0;    //紀錄目前場上的顏色數量
        vector<int> res;
        for(int i=0;i<n;i++){
            int ball=queries[i][0];
            int color=queries[i][1];
            int original=balls.count(ball)? balls[ball]:-1;    //那顆球之前的顏色，如果沒被塗色過，其值為-1
            if(original!=-1){    //如果之前被塗過色
                if(--hash[original]==0)//之前的顏色要扣掉一顆球，因為她要被改色了
                    color_nums--;    //而如果當前的顏色變為0了，那場上的顏色總數會少一個
            }
            if(++hash[color]==1)//把要改的顏色數量往上加，如果他新增厚的數值恰巧等於1，代表場上多了一個新的顏色，color_num++
                color_nums++;
            balls[ball]=color;    //最後把球的顏色改掉
            res.push_back(color_nums);//當前場上顏色數新增至結果裡
        }
        return res;
    }
};
