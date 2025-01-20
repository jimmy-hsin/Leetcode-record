class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        //建立哈希表，以便後續快速取出arr[i]在mat上的位置
        unordered_map<int,pair<int,int>> hash;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                hash[mat[i][j]]={i,j};
        }
        
        vector<int> row(m,0);
        vector<int> col(n,0);
        for(int i=0;i<arr.size();i++){
            auto [x,y]=hash[arr[i]];    //從哈希表取出位置
            row[x]++;
            col[y]++;
            if(row[x]==n || col[y]==m)    //若當前要填入的行/列以湊滿
                return i;                 //就回傳
        }
        return 0;
    }
};
