class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        int k=arr.size();
        //用Vector替代Hash Table 的開銷比較小
        //我們先創建兩個vector，以便我們後續快速查找arr[i]在mat中的位置
        vector<int> numToRow(k+1);
        vector<int> numToCol(k+1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                numToRow[mat[i][j]]=i;
                numToCol[mat[i][j]]=j;
            }
        }
        //再來創建兩個vector, 他們可以統計每一排，每一列現在標記多少塊方塊了
        vector<int> row(m,0);
        vector<int> col(n,0);
        for(int i=0;i<arr.size();i++){
            int x=numToRow[arr[i]];
            int y=numToCol[arr[i]];
            if(++row[x]==n || ++col[y]==m)    //如果當前要填入的行(row)，或列(col) 填入這個方塊後就湊滿了的話，就直接回傳i值
                return i;
        }
        return 0;
    }
};
