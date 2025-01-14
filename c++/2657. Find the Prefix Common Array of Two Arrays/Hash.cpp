class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        unordered_set<int> a, b;
        vector<int> res(n,0);
        int common=0;
        for(int i=0;i<n;i++){
            a.insert(A[i]);
            common+=b.count(A[i]);
            b.insert(B[i]);
            common+=a.count(B[i]);
            res[i]=common;
        }
        return res;
    }
};
