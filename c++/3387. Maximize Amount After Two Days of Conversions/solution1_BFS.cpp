#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <utility>

double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
  //紀錄1元的initial可以換成多多的other currency，應該要盡可能換大最大數量的other currency，我們第二天才可以換回最大的initial currency
    unordered_map<string,double> amount1; 
    BFS(initialCurrency,amount1, pairs1, rates1, true);
  
//1元的initial可以換成多少的other currency, 應該讓1元的initial currency對other currency的匯率盡可能的低(1元的other currency 可以換到越多的initial currency)
    unordered_map<string,double> amount2; 
    BFS(initialCurrency,amount2, pairs2, rates2, false);
    
    double res=0.0;
    for(auto& pair:amount1){
        auto [currency, rate1]=pair;
        if(amount2.count(currency)){
            double temp=rate1/amount2[currency];  //第一天用1元initial可以換到的數量/ 第二天的匯率
            res=max(res,temp);
        }
    }
    return res;
}
void BFS(string initialCurrency,unordered_map<string,double>& amount, vector<vector<string>>& pairs, vector<double>& rates, bool m){
  //Build graph for day 1 or 2
    unordered_map<string, vector<pair<string,double>>> map;
    for(int i=0;i<pairs.size();i++){
        map[pairs[i][0]].push_back({pairs[i][1], rates[i]});
        map[pairs[i][1]].push_back({pairs[i][0], 1.0/rates[i]});
    }
  //BFS to calculate minimum amounts for day 2
    queue<string> q;
  //把起始貨幣塞進隊列
    q.push(initialCurrency);
  //匯兌基準為1.0個起始貨幣
    amount[initialCurrency]=1.0;
    while(!q.empty()){
        string currC=q.front();
        q.pop();
        for(auto& [nextC,rate]:map[currC]){
          //如果貨幣(nextC)的匯率還沒被記錄過
            if(!amount.count(nextC)){
                amount[nextC]=amount[currC]*rate;
                q.push(nextC);
            }
          //如果記錄過了，但我們想知道兌換結果的最大值
            else if(m)
                amount[nextC]=max( amount[nextC], amount[currC]*rate);
          //如果記錄過了，但我們想知道兌換結果的最小值
            else
                amount[nextC]=min( amount[nextC], amount[currC]*rate);
        }
    }
}
