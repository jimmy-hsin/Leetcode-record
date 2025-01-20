class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        int k=arr.size();
        vector<int> numToRow(k+1);
        vector<int> numToCol(k+1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                numToRow[mat[i][j]]=i;
                numToCol[mat[i][j]]=j;
            }
        }
        vector<int> row(m,0);
        vector<int> col(n,0);
        for(int i=0;i<arr.size();i++){
            int x=numToRow[arr[i]];
            int y=numToCol[arr[i]];
            row[x]++;
            col[y]++;
            if(row[x]==n || col[y]==m)
                return i;
        }
        return 0;
    }
};
