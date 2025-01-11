class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;  //stack裡所存的值，代表每個chunk中的最大元素
        int currMax=arr[0];
        for(int i:arr){
            while(!st.empty() && i<st.top())  //如果掃到的元素i，比stack的最上面元素還小，代表他要被納入前面的chunk中，
                st.pop();                     //如果pop()一次之後，還是比下一個top()還小，那代表前面兩個chunk要整合再一起才合規
                                              //直到pop()到top()比i還小為止，代表i可以排進top()後面的那個chunk中
            currMax=max(currMax,i);           //我們紀錄目前掃到的最大值
            st.push(currMax);                 //然後重新把currMax塞回stack，作為最後一個chunk的最大元素
        }
        return st.size();                     //最後我們看我們收集到幾個chunk，就是答案了
    }
};
