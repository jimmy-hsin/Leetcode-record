class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int currMax=values[0]+0;
        int res=0;
        for(int i=1;i<values.size();i++){
            int temp=values[i]-i+currMax;
            currMax=max(values[i]+i,currMax);
            res=max(res,temp);
        }
        return res;
    }
};

/*
  由於分數的計算是values[a] + values[b] + a - b，那我們先把它拆項成 (values[a]+a) + (values[b]-b)，
  我們可以用currMax來記錄先前最大的(values[a]+a)的值，後一項的b為我們當前掃描到的(i)，所以我們能求出當前的元素i 與前項配對的最大分數(用temp記起來)，
  然後我們再紀錄一路掃描以來的最大分數就解決問題了
*/
