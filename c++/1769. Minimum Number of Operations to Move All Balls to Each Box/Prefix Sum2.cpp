class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n, 0);
        //往前看跟往後看要補多少距離，各做一次
      //front
        int count = 0, op = 0; 
        for(int i = 0; i < n; i++){
            res[i] += op;
            count += (boxes[i] -'0');
            op+= count;
        }
      //behind
        count = 0, op = 0;
        for(int i = n - 1; i >= 0; i--){
            res[i] += op;
            count += (boxes[i] -'0');
            op += count;
        }
        
        return res;
    }
};
