class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        bool res=0;
        for(int& i:derived)
            res^=i;
        return !res;
    }
};
