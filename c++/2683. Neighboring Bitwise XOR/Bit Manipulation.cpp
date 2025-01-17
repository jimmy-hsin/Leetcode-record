class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        /*
            先嘗試理解題意: 我們有一個origin array，用來產生derived array，
            透過題目的規則，我們可以發現到一件事，就是每個origin array裡的元素都會被拿來操作XOR operation 兩次
            所以理論上得出的derived array 全部做完XOR 之後的答案應該為0，所以我們找出對derived通乘(XOR)之後，就知道答案了
        */
        bool res=1;
        for(int& i:derived)
            res^=i;
        return res;
    }
};
