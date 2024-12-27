class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        st.push(prices.back());
        for(int i=prices.size()-2;i>=0;i--){
            while(!st.empty() && prices[i]<st.top())
                st.pop();
            int temp=prices[i];
            if(!st.empty())
                prices[i]-=st.top();
            st.push(temp);
        }
        return prices;
    }
};
/*
  題目的要求是，第i個商品的折扣價格為，i 之後最靠近 i 且價格<price[i]的元素。
  所以最後一個商品無法打折，因為他後面沒有其他元素，因此掃描從n-2開始掃到0
  stack 裡面存放的都是小於prices[i]的元素，約深的地方數值越小，且距離當前的元素i 越遠，是為一個monotonic stack
  這個資料結構可以讓我們取出i 之後最靠近且小於i的值
  若他後面存在這個一個元素，那我們把它打折後的價格存回array，然後把元素i的初始值推進stack中
*/
