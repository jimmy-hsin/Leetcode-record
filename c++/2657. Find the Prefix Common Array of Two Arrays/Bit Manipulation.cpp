class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        bitset<51> a;
        bitset<51> b;
        vector<int> res(n,0);
        int common=0;
        for(int i=0;i<n;i++){
            a.set(A[i]);
            common+=b[A[i]];
            b.set(B[i]);
            common+=a[B[i]];
            res[i]=common;
        }
        return res;
    }
};
