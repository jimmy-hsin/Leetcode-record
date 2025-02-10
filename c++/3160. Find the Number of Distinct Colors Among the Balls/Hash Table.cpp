class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
	    unordered_map<int,int> balls;//balls,color
        unordered_map<int,int> hash;// color, counts
        int color_nums=0;
        vector<int> res;
        for(int i=0;i<n;i++){
            int ball=queries[i][0];
            int color=queries[i][1];
            int original=balls.count(ball)? balls[ball]:-1;
            if(original!=-1){
                if(--hash[original]==0)
                    color_nums--;
            }
            if(++hash[color]==1)
                color_nums++;
            balls[ball]=color;
            res.push_back(color_nums);
        }
        return res;
    }
};
