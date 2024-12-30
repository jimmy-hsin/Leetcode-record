class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> hash;
        for(int i:arr){
            if(hash.count(2*i) || ((i%2==0) && hash.count(i/2)))
                return true;
            hash.insert(i);
        }
        return false;
    }
};
